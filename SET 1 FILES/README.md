# Computational Screening of Candidate Split Suppressor-tRNAs in *Methanosarcina barkeri* str. Wiesmoor

A position-specific probabilistic pipeline that scans a complete archaeal genome for **split tRNA genes** (tRNAs stored as two separate halves). It joins candidate halves, scores them against a profile built from known tRNAs, calibrates every score against decoys drawn from shuffled genomes, and applies **G+C composition criteria** derived from known tRNAs.

This repository contains the **executable source code, input sequences, genome accessions, model and scoring procedures, randomisation procedure, candidate reconstruction and filtering steps, G+C analysis, and the complete results**, including the predicted candidates, their constituent fragments and the randomised-genome decoys.

**Accompanying manuscript:** *A Position-Specific Probabilistic Model for Computational Screening of Split Suppressor-tRNA Candidates in* Methanosarcina barkeri *strain Wiesmoor* (under review).

---

## Table of Contents

1. [What problem does this solve?](#1-what-problem-does-this-solve)
2. [How does it work?](#2-how-does-it-work)
3. [Data sources](#3-data-sources)
4. [Repository contents](#4-repository-contents)
5. [Reproducing the analysis](#5-reproducing-the-analysis)
6. [Results](#6-results)
7. [Decision framework (Stages A, B, C)](#7-decision-framework-stages-a-b-c)
8. [Notes on methodology](#8-notes-on-methodology)
9. [How to cite](#9-how-to-cite)
10. [Contact](#10-contact)

---

## 1. What problem does this solve?

A normal tRNA gene sits in the genome **in one piece**.

A **split tRNA gene does not**. It is stored as two separate pieces, a **5′ half** and a **3′ half**, sometimes very far apart. The cell transcribes both pieces and joins them afterwards to make one working tRNA.

Split tRNAs are hard to find, because **neither half looks like a tRNA on its own**, and standard tRNA predictors look for a complete tRNA in one continuous stretch of the genome. This pipeline looks for the halves and joins them.

**Why a documented implementation matters:** it allows other researchers to verify the results, examine the candidate-selection procedure and build on the method.

---

## 2. How does it work?

Seven simple steps.

| Step | What happens | Why it matters |
|---|---|---|
| **1. Learn what a real tRNA looks like** | Take **199 known tRNAs**, all aligned at **72 standard (Sprinzl) positions**. At each position, count how often **A, C, G and U** appear. | This gives the *profile* of a typical tRNA. |
| **2. Search the genome for halves** | Scan **both strands** of the *M. barkeri* genome and record every stretch that looks like a tRNA **5′ half** or **3′ half**. | Halves are the only signal available; a split gene has no intact copy. |
| **3. Join the halves** | Pair each 5′ half with each 3′ half and join them. The join point is **always position 37/38**. | **Not a guess.** 37/38 is the normal intron position in archaeal tRNAs and the position where real split tRNAs are joined. **No other join position was used.** |
| **4. Apply structural filters** | Keep only joined sequences that form the cloverleaf (stems, conserved positions, tertiary interactions), carry a stop-codon-complementary anticodon and form a BHB splice-site structure. | Removes sequences that cannot be tRNAs. |
| **5. Score each joined sequence** | Compare it with the profile from Step 1 (emission and transition log-odds) and give it a combined score **S**. | A high score means *"this looks like a real tRNA"*. |
| **6. Check against fakes** | **Shuffle the genome 50 times** and run the *exact same pipeline* on each shuffled copy. Anything found there is a false positive by definition. | These are the **decoys**; they set the pass mark. A score means little on its own. |
| **7. Apply the G+C criteria** | Measure G+C in the **stems** and in the rest of the tRNA. Real tRNA stems are rich in G and C (a G–C pair forms three hydrogen bonds, an A–U pair two); loops are not. | An extra, independent requirement set from known tRNAs only. It removes all decoys while keeping 92–98% of real tRNAs. |

---

## 3. Data sources

| Dataset | Source | Link |
|---|---|---|
| **Genome:** *Methanosarcina barkeri* str. Wiesmoor chromosome, complete genome | NCBI Nucleotide, **GenBank CP009526.1** (RefSeq NZ_CP009526.1) | [ncbi.nlm.nih.gov/nuccore/CP009526.1](https://www.ncbi.nlm.nih.gov/nuccore/CP009526.1/) |
| **Reference tRNA set:** 199 known tRNAs (one duplicate record, tdbR00000504, removed from 200) | **T-psi-C** database | [tpsic.igcz.poznan.pl](https://tpsic.igcz.poznan.pl/info/start/) |
| **Same-species known tRNAs** (mature; tRNAscan-SE annotations) | **GtRNAdb**, *M. barkeri* Wiesmoor | [gtrnadb.org](https://gtrnadb.org/genomes/archaea/Meth_bark_Wiesmoor/) |

---

## 4. Repository contents

Files are grouped into seven sets. In every table the **description is on the left** and the **file name is on the right**. In SETS IV, VI and VII, the column **Manuscript** shows where a file appears in the paper.

### SET I: Genome scan and structural filters

| # | Description | File |
|---|---|---|
| 1 | *M. barkeri* str. Wiesmoor chromosome, complete genome (CP009526.1) | see [Data sources](#3-data-sources) |
| 2 | Input sequence (genome prepared for the scan) | `input.txt` |
| 3 | Output: base pairs of nucleotides | `output_base_pair` |
| 4 | Output: tRNA secondary structures (9 candidates) | `output_tRNA_2D_Structure` |
| 5 | Flow diagram of the two-phase pipeline with G+C filter (manuscript Figure 2) | `tRNA_two_phase_flow_diagram_GC` |
| 6 | Pseudocode: Phase I, Phase II and G+C filter | `Split_tRNA_pseudocode_PhaseI_PhaseII_GC` |
| 7 | **Source code (C):** genome scan and structural filters | `split2_trna_added_371.c` |
| 8 | **Genome shuffler (C):** generates the randomised genomes for the decoys | `random1.c` |
| 9 | Readme file | `README.md`, `readme1.docx` |

### SET II: tRNA datasets, decoys and predicted candidates (sequence + dot-bracket)

| # | Description | File |
|---|---|---|
| 10 | **REF:** reference set of 199 known tRNAs from the T-psi-C database | `trna_data_rev3_199_tpsic` |
| 11 | **VAL1:** known tRNAs of the same species (mature), **held out of REF**. The file holds 63 entries; tRNA-Und-NNN-1-1 (undetermined isotype) is excluded, giving **62** | `tRNA63__tRNAScan_MBSW_1` |
| 12 | **VAL2:** 96 further known tRNAs from the T-psi-C database, **held out of REF** | `random_96_T_psi_c_trna` |
| 13 | **DECOY:** 13 sequences recovered from the 50 shuffled genomes | `tRNA13_RANDOM_SEQUENCE_2` |
| 14 | **CAND:** the 9 predicted candidates | `Candidate9_FASTA_SEQUENCE_Withdot`, `candidate_tRNA_9` |
| 15 | Complete fragment table: 5′/3′ pairings and genome coordinates | `new genome_tRNA_9_rev3` |

### SET III: Sequences on the position-specific profile (Sprinzl positions 1–72)

At each position, counts of **A, C, G and U** across positions **1–72**.

| # | Description | File |
|---|---|---|
| 16 | Reference set: **199 known tRNAs** on positions 1–72 | `tRNA_Database_T_Psi_C_199_1` |
| 17 | Same-species known tRNAs (VAL1, 62) on positions 1–72 | `tRNA__tRNAScan_MBSW_62_2` |
| 18 | Further known T-psi-C tRNAs (VAL2, 96) on positions 1–72 | `tRNA_T_Psi_C_96_OTHER` |
| 19 | Decoys from the **shuffled genomes** (13) on positions 1–72 | `tRNA_random_13_positions_1-72` |
| 20 | **Predicted candidates** (9) on positions 1–72 | `candidate_tRNA_3` |
| 21 | **Combined (19 + 20):** predicted candidates and decoys together | `TOTAL_CANDIDATE_RANDOM_TRUE` |

### SET IV: Structural and probabilistic assessment

| # | Description | File | Manuscript |
|---|---|---|---|
| 22 | Construction and validation of the position-specific model, and structural and probabilistic assessment of the 9 candidates | `Supplementary_Data_S1_tRNA_validation_REV3_199` | **Supplementary Data S1** |
| 23 | Validation of the 9 candidates against the realistic negative control (randomised-genome decoys) | `tRNA_v6_Final_Validation_Excel2007_REV3_199` | Supporting file |

### SET V: G+C composition by structural region

Each file reports G+C for the **whole tRNA (positions 1–72)**, the **4 stems**, the **tertiary (3D) base pairs** and the **4 loops**, and **dGC = GC_stem − GC_nonstem**. Together, files 24–29 form **Supplementary Data S2**.

| # | Dataset | File |
|---|---|---|
| 24 | T-psi-C reference tRNAs (REF, 199) | `TpsiC_199_tRNA_GC_content_stems_3D_loops_Dgc` |
| 25 | *M. barkeri* str. Wiesmoor genomic tRNAs (VAL1, 62) | `MBSW_tRNA_GC_content_stems_3D_loops_v2_dGC` |
| 26 | Further T-psi-C tRNAs (VAL2, 96) | `TpsiC_tRNA_GC_content_stems_3D_loops_dGC` |
| 27 | Decoys from the shuffled genomes (13) | `Random_tRNA_GC_content_stems_3D_loops_dGC` |
| 28 | Predicted candidates (9) | `tRNA_GC_content_stems_3D_loops_dGC` |
| 29 | **Summary:** G+C in stems vs non-stem regions, all datasets compared | `tRNA_GC_dGC_Summary_for_REV3` |

### SET VI: GC criteria and final validation status

| # | Description | File | Manuscript |
|---|---|---|---|
| 30 | GC criteria (C1–C3), reference GC distributions, combined score + GC analysis, effect on the search output, GC definition, and **final validation status** of the 9 candidates | `Final_Validation_Status_tRNA_candidates` | **Supplementary Data S3** |

### SET VII: Final summary and manuscript tables

| # | Description | File | Manuscript |
|---|---|---|---|
| 31 | Final validation summary of the 9 predicted split suppressor / Sec tRNA candidates, plan of the manuscript tables, and consistency check | `Final_Validation_Summary_and_Manuscript_Tables` | Supporting file |
| 32 | Manuscript-ready tables with titles and legends | `Manuscript_Tables_3-5` | **Tables 3, 4 and 5** |

---

## 5. Reproducing the analysis

### Requirements

- A **C compiler** (gcc or any C99-compatible compiler) for `split2_trna_added_371.c` and `random1.c`
- A **spreadsheet application**; all tabulated results are supplied as **Excel 2007-compatible** workbooks
- The genome sequence for **CP009526.1**, prepared as `input.txt`

### Step by step

**Step 1: Get the genome.** Download the complete chromosome of *M. barkeri* str. Wiesmoor from [NCBI accession CP009526.1](https://www.ncbi.nlm.nih.gov/nuccore/CP009526.1/) and place the sequence in `input.txt`, in the same format as the supplied copy.

**Step 2: Build the reference profile.** The profile is the **positional A/C/G/U composition of 199 known tRNAs** aligned on Sprinzl positions 1–72, as tabulated in `tRNA_Database_T_Psi_C_199_1` (sequences in `trna_data_rev3_199_tpsic`). Emission and transition probabilities use add-one smoothing (see S1, sheets *Formulas*, *Emission Matrix*, *Transition Prob Matrices*).

**Step 3: Run the genome scan and structural filters.**

```bash
gcc -O2 -o split2_trna split2_trna_added_371.c
./split2_trna
```

This searches for halves on **both strands**, joins them at **37/38** and applies the structural filters. Compare your output with the supplied `output_base_pair` and `output_tRNA_2D_Structure`.

**Step 4: Generate the randomised genomes (decoys).**

```bash
gcc -O2 -o random1 random1.c
./random1
```

Produce **50 shuffled copies** of the genome, then re-run **Step 3 unchanged** on each one. Sequences recovered here are false positives by construction. They form the decoy set in `tRNA13_RANDOM_SEQUENCE_2` and `tRNA_random_13_positions_1-72`.

**Step 5: Score and calibrate the pass mark.** Score all sequences with the profile. The threshold is set midway between the highest decoy score (−0.1890) and the weakest known tRNA (+0.0288), giving **S = −0.0801**. The calibrated comparison is in `tRNA_v6_Final_Validation_Excel2007_REV3_199` and `Supplementary_Data_S1_tRNA_validation_REV3_199`; the combined candidate-plus-decoy table is `TOTAL_CANDIDATE_RANDOM_TRUE`.

**Step 6: Apply the G+C criteria.** Compute overall GC, GC in the 42 stem positions and dGC for each sequence (positions 1–72, missing positions excluded), as in SET V. Apply the three criteria, which are the 5th percentiles of the 199 reference tRNAs:

| Criterion | Threshold |
|---|---|
| C1: overall GC | ≥ 49.2% |
| C2: GC_stem | ≥ 24 of 42 stem positions (57.1%) |
| C3: dGC | ≥ +14.9 percentage points |

Cross-check against `tRNA_GC_dGC_Summary_for_REV3` and the *GC_Criteria* sheet of `Final_Validation_Status_tRNA_candidates`.

**Step 7: Read off the final status.** Candidate-by-candidate outcomes are in `Final_Validation_Status_tRNA_candidates` (S3), with supporting detail in `Supplementary_Data_S1_tRNA_validation_REV3_199` (S1). The manuscript tables are in `Manuscript_Tables_1-3`.

**Reference checkpoints.** Every intermediate output above has a committed counterpart in this repository, so each stage can be checked on its own rather than only at the end.

---

## 6. Results

Nine candidates were predicted and carried through all three assessment stages.

| Outcome | Candidate(s) | Why |
|---|---|---|
| **Supported** | `trna64` (Sec, UCA) | S = +0.0394, above the threshold and within the range of known tRNAs; meets all 3 GC criteria (GC 64.8%, GC_stem 34/42, dGC +39.6) |
| **Borderline** | `trna958` (Sup, CUA) | S = −0.1423, above every decoy but below the threshold; meets 0 of 3 GC criteria |
| **Not supported** | `trna1091`, `trna1395`, `trna1`, `trna20`, `trna9`, `trna590`, `trna1470` | Scores within the decoy range (−0.2388 to −0.4932) |

Key numbers:

- Known tRNAs vs both negative controls: complete separation (AUC = 1.000).
- Candidates vs decoys: score alone AUC 0.615; score + G+C features AUC 0.829 (p = 0.011).
- G+C criteria: accept 92–98% of known tRNAs and 0 of 13 decoys.
- False positives: 0.26 per randomised genome before the G+C criteria, 0 after.
- Power limit: with 13 decoys the smallest attainable p value is 1/14 = 0.071.

---

## 7. Decision framework (Stages A, B, C)

| Stage | What it is | Role in the decision |
|---|---|---|
| **Stage A** | Position-specific probabilistic model, **decoy-calibrated** | **Decisive** |
| **Stage B** | Structural features (stem pairing, conserved positions, T-loop) | **Reported, but not used in the decision** |
| **Stage C** | **G+C composition criteria** (C1–C3) derived from the reference tRNAs only | **Decisive** (additional requirement) |

**Decision rule** (fixed before it was applied):

- **Supported:** S above the threshold (−0.0801) **and** all three G+C criteria met.
- **Borderline:** S above every decoy, but not supported.
- **Not supported:** S within the decoy range, whatever the G+C profile.

G+C is an **additional requirement only**; it is never used to rescue a candidate that Stage A rejects.

**G+C definition.** Canonical positions 1–72, with missing positions excluded from both numerator and denominator.

---

## 8. Notes on methodology

- **The 37/38 join point is fixed, not fitted.** It is the normal intron position in archaeal tRNAs and the position at which real split tRNAs are joined. **No alternative join position was used.**
- **Decoys come from the same pipeline.** The shuffled genomes are processed by the *identical* code path, so the null distribution reflects the method itself, not a separate approximation.
- **Held-out validation sets.** **VAL1** (same-species mature tRNAs) and **VAL2** (further T-psi-C tRNAs) were **held out of REF** and never contributed to the profile.
- **VAL1 is not a gold standard.** The 62 *M. barkeri* tRNAs are tRNAscan-SE computational annotations, not experimentally confirmed tRNAs; they serve as an organism-specific reference distribution.
- **G+C thresholds were not tuned on the result.** They are the 5th percentiles of the 199 reference tRNAs; candidates and decoys were not used to set them.
- **Computational evidence only.** Transcription, processing, aminoacylation and stop-codon suppression of the candidates have not been tested experimentally.
- **Tools used throughout the work.** C programs for the scan and shuffling; spreadsheets for the tabulated calculations; programming for the ROC and Mann–Whitney statistics; manual pen-and-paper checks of intermediate results; and AI assistance for checking and correcting results.
- **Spreadsheet compatibility.** All tabulated results are provided as **Excel 2007-compatible** workbooks.

---

## 9. How to cite

If you use this code or data, please cite the accompanying manuscript:

> [U. Roy Mandal, S.Das and K.maity]. A Position-Specific Probabilistic Model for Computational Screening of Split Suppressor-tRNA Candidates in *Methanosarcina barkeri* strain Wiesmoor. [Journal of Bioinformatics and Computational Biology], [2026]. DOI: [to be added]

---

## 10. Contact

Given the number of files and the range of calculations involved, questions are welcome.

**Email:** [urmandal@gmail.com](mailto:urmandal@gmail.com)

---

<div align="center">

*Split suppressor-tRNA screen · **Methanosarcina barkeri** str. Wiesmoor · Genome accession **CP009526.1***

</div>
