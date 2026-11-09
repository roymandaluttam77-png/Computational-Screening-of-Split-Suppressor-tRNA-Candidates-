# Computational Screening of Candidate Split Suppressor-tRNAs in *Methanosarcina barkeri* str. Wiesmoor

A **three-stage computational workflow** that scans a complete archaeal genome for **split tRNA genes** (tRNAs encoded as two separate halves):

- **Stage I, structural search:** finds and joins candidate 5′ and 3′ halves and applies structural filters.
- **Stage II, probabilistic score:** scores each joined sequence against a position-specific model built from known tRNAs.
- **Stage III, GC criteria:** applies G+C composition criteria derived from the same known tRNAs.

Every stage is applied in the same way to **decoys**, the sequences the identical search returns from randomized copies of the genome.

This repository contains the **executable source code, input sequences, genome accession, model and scoring procedures, randomization procedure, candidate reconstruction and filtering steps, G+C analysis, and the complete results**. The results cover the candidates, their constituent fragments and the decoys.

**Accompanying manuscript:** *A Position-Specific Probabilistic Model for Computational Screening of Split Suppressor-tRNA Candidates in* Methanosarcina barkeri *strain Wiesmoor* (under review).

---

## Table of Contents

1. [What problem does this solve?](#1-what-problem-does-this-solve)
2. [How does it work? The three-stage workflow](#2-how-does-it-work-the-three-stage-workflow)
3. [Data sources](#3-data-sources)
4. [Repository contents](#4-repository-contents)
5. [Reproducing the analysis](#5-reproducing-the-analysis)
6. [Results](#6-results)
7. [Decision rule](#7-decision-rule)
8. [Notes on methodology](#8-notes-on-methodology)
9. [How to cite](#9-how-to-cite)
10. [Contact](#10-contact)

---

## 1. What problem does this solve?

A normal tRNA gene sits in the genome **in one piece**.

A **split tRNA gene does not**. It is encoded as two separate pieces, a **5′ half** and a **3′ half**, sometimes far apart. Both pieces are transcribed and then joined to make one mature tRNA.

Split tRNAs are hard to find, because **neither half looks like a tRNA on its own**, and standard tRNA predictors look for a complete tRNA in one continuous stretch of the genome. This workflow looks for the halves, joins them, and tests whether the joined sequence behaves like a real tRNA.

**Why a documented implementation matters:** it allows other researchers to verify the results, examine how candidates are selected and build on the method.

---

## 2. How does it work? The three-stage workflow

The whole workflow is shown in **Figure 2** (`Figure2_workflow`). The same steps are applied to the MBSW genome (giving **candidates**) and to **50 randomized genomes** (giving **decoys**).

| Stage | What happens | Why it matters |
|---|---|---|
| **Stage I: structural search** | Scan **both strands** for tRNA **5′ halves** (positions 1–37) and **3′ halves** (positions 38–72). Join compatible halves at **position 37/38** and map them onto the **72 standard (Sprinzl) positions**. Keep only sequences that form the cloverleaf (four stems, at most 2 non-Watson–Crick pairs), keep the conserved positions and tertiary interactions, carry a **UCA, CUA or UUA** anticodon and form a **bulge–helix–bulge (BHB)** split site. | Removes sequences that cannot be tRNAs. **37/38 is not a guess:** it is the normal intron position in archaeal tRNAs and the position where real split tRNAs are joined. No other join position was used. |
| **Same search on randomized genomes** | **Shuffle the genome 50 times** (base composition preserved) and run the *identical* Stage I on each copy. The sequences found are the **decoys**. | Randomized genomes contain no tRNA genes, so decoys show what the search returns by chance. They are the realistic negative control. |
| **Stage II: probabilistic score** | Build a profile from **199 known tRNAs** (A/C/G/U frequency at each of 72 positions, plus neighbor transitions). Score every candidate and decoy with a combined score **S** (mean emission and transition log-odds). Set the threshold **τ = −0.0801** midway between the highest decoy and the weakest held-out known tRNA. | Tests whether a sequence has the **positional sequence pattern** of a real tRNA. |
| **Stage III: GC criteria** | Measure G+C overall, in the 42 **stem** positions, and the stem-minus-non-stem difference (**dGC**). Apply three criteria set from the 199 known tRNAs only (5th percentiles). | Real tRNA stems are GC-rich because a G–C pair forms three hydrogen bonds and an A–U pair two. The criteria keep 92–98% of known tRNAs and **none** of the decoys. |
| **Final decision rule** | Combine Stage II and Stage III (Section 7) and classify each candidate as **supported**, **borderline** or **not supported**. | Both properties are required; GC never rescues a sequence whose score looks like a decoy. |

---

## 3. Data sources

| Dataset | Source | Link |
|---|---|---|
| **Genome:** *Methanosarcina barkeri* str. Wiesmoor chromosome, complete genome | NCBI Nucleotide, **GenBank CP009526.1** (RefSeq NZ_CP009526.1) | [ncbi.nlm.nih.gov/nuccore/CP009526.1](https://www.ncbi.nlm.nih.gov/nuccore/CP009526.1/) |
| **Reference tRNA set:** 199 known tRNAs (one duplicate record, tdbR00000504, removed from 200) | **T-psi-C** database | [tpsic.igcz.poznan.pl](https://tpsic.igcz.poznan.pl/info/start/) |
| **Same-species known tRNAs** (tRNAscan-SE annotations) and the conventional annotation used for comparison | **GtRNAdb**, *M. barkeri* Wiesmoor | [gtrnadb.org](https://gtrnadb.org/genomes/archaea/Meth_bark_Wiesmoor/) |

---

## 4. Repository contents

Files are grouped into seven sets. In every table the **description is on the left** and the **file name is on the right**. In SETS IV, VI and VII, the column **Manuscript** shows where a file appears in the paper.

### SET I: Genome, source code and workflow (Stage I)

| # | Description | File |
|---|---|---|
| 1 | *M. barkeri* str. Wiesmoor chromosome, complete genome (CP009526.1) | see [Data sources](#3-data-sources) |
| 2 | Input sequence (genome prepared for the scan) | `input.txt` |
| 3 | Output: base pairs of nucleotides | `output_base_pair` |
| 4 | Output: tRNA secondary structures (9 candidates) | `output_tRNA_2D_Structure` |
| 5 | Three-stage workflow diagram (**manuscript Figure 2**) | `Figure2_workflow` |
| 6 | Pseudocode of the three-stage workflow | `Split_tRNA_pseudocode_three_stage` |
| 7 | **Source code (C):** genome scan and structural filters (Stage I) | `split2_trna_added_371.c` |
| 8 | **Genome shuffler (C):** generates the 50 randomized genomes | `random1.c` |
| 9 | Readme file | `README.md`, `readme1.docx` |

### SET II: tRNA datasets, decoys and candidates (sequence + dot-bracket)

| # | Description | File |
|---|---|---|
| 10 | **REF:** reference set of 199 known tRNAs from the T-psi-C database | `trna_data_rev3_199_tpsic` |
| 11 | **VAL1:** known tRNAs of the same species, **held out of REF**. The file holds 63 entries; tRNA-Und-NNN-1-1 (undetermined isotype) is excluded, giving **62** | `tRNA63__tRNAScan_MBSW_1` |
| 12 | **VAL2:** 96 further known tRNAs from the T-psi-C database, **held out of REF** | `random_96_T_psi_c_trna` |
| 13 | **Decoys:** the 13 structural-search hits from the 50 randomized genomes | `tRNA13_RANDOM_SEQUENCE_2` |
| 14 | **Candidates:** the 9 structural-search hits from the MBSW genome | `Candidate9_FASTA_SEQUENCE_Withdot`, `candidate_tRNA_9` |
| 15 | Complete fragment table: 5′/3′ pairings and genome coordinates | `new genome_tRNA_9_rev3` |

### SET III: Sequences on the position-specific profile (Sprinzl positions 1–72)

At each position, counts of **A, C, G and U** across positions **1–72**.

| # | Description | File |
|---|---|---|
| 16 | Reference set: **199 known tRNAs** on positions 1–72 | `tRNA_Database_T_Psi_C_199_1` |
| 17 | Same-species known tRNAs (VAL1, 62) on positions 1–72 | `tRNA__tRNAScan_MBSW_62_2` |
| 18 | Further known T-psi-C tRNAs (VAL2, 96) on positions 1–72 | `tRNA_T_Psi_C_96_OTHER` |
| 19 | **Decoys** (13) on positions 1–72 | `tRNA_random_13_positions_1-72` |
| 20 | **Candidates** (9) on positions 1–72 | `candidate_tRNA_3` |
| 21 | **Combined (19 + 20):** candidates and decoys together | `TOTAL_CANDIDATE_RANDOM_TRUE` |

### SET IV: Stage II, probabilistic score

| # | Description | File | Manuscript |
|---|---|---|---|
| 22 | Construction and validation of the position-specific model, scores of all sets, threshold calibration, and structural measures of the candidates and decoys | `Supplementary_Data_S1_tRNA_validation_REV3_199_R2` | **Supplementary Data S1** |

### SET V: Stage III, G+C composition by structural region

Each file reports G+C for the **whole tRNA (positions 1–72)**, the **4 stems**, the **tertiary (3D) base pairs** and the **4 loops**, and **dGC = GC_stem − GC_nonstem**. Together, files 23–28 form **Supplementary Data S2**.

| # | Dataset | File |
|---|---|---|
| 23 | T-psi-C reference tRNAs (REF, 199) | `TpsiC_199_tRNA_GC_content_stems_3D_loops_Dgc` |
| 24 | *M. barkeri* str. Wiesmoor tRNAs (VAL1, 62) | `MBSW_tRNA_GC_content_stems_3D_loops_v2_dGC` |
| 25 | Further T-psi-C tRNAs (VAL2, 96) | `TpsiC_tRNA_GC_content_stems_3D_loops_dGC` |
| 26 | Decoys (13) | `Random_tRNA_GC_content_stems_3D_loops_dGC` |
| 27 | Candidates (9) | `tRNA_GC_content_stems_3D_loops_dGC` |
| 28 | **Summary:** G+C in stems vs non-stem regions, all datasets compared | `tRNA_GC_dGC_Summary_for_REV3` |

### SET VI: GC criteria, decision rule and final status

| # | Description | File | Manuscript |
|---|---|---|---|
| 29 | GC criteria (C1–C3) and their reference statistics, percentile sensitivity, discrimination of candidates from decoys with and without S, decoy hit rate in the 50 randomized genomes, stage-by-stage results, decision rule and **final status** of the 9 candidates | `Final_Validation_Status_tRNA_candidates_R2` | **Supplementary Data S3** |

### SET VII: Summary, manuscript tables and figures, and value verification

| # | Description | File | Manuscript |
|---|---|---|---|
| 30 | Final validation summary of the 9 candidates and plan of the manuscript tables | `Final_Validation_Summary_and_Manuscript_Tables_FINAL` | Supporting file |
| 31 | Manuscript-ready tables with titles and legends | `Manuscript_Tables_3-6_FINAL` | **Tables 3–6** |
| 32 | Distribution of the three GC criteria in reference tRNAs, candidates and decoys | `Figure_GC_criteria_distributions` | **Figure 4** |
| 33 | Every number quoted in the Results recomputed by formula and checked against the manuscript | `Manuscript_Value_Verification` | Supporting file |

---

## 5. Reproducing the analysis

### Requirements

- A **C compiler** (gcc or any C99-compatible compiler) for `split2_trna_added_371.c` and `random1.c`
- A **spreadsheet application**; all tabulated results are supplied as **Excel 2007-compatible** workbooks
- The genome sequence for **CP009526.1**, prepared as `input.txt`

### Stage I: structural search

**Step 1: Get the genome.** Download the complete chromosome of *M. barkeri* str. Wiesmoor from [NCBI accession CP009526.1](https://www.ncbi.nlm.nih.gov/nuccore/CP009526.1/) and place the sequence in `input.txt`, in the same format as the supplied copy.

**Step 2: Run the structural search on the real genome.**

```bash
gcc -O2 -o split2_trna split2_trna_added_371.c
./split2_trna
```

This searches for halves on **both strands**, joins them at **37/38** and applies the structural filters. Compare your output with the supplied `output_base_pair` and `output_tRNA_2D_Structure` (9 candidates).

**Step 3: Generate the randomized genomes and their decoys.**

```bash
gcc -O2 -o random1 random1.c
./random1
```

Produce **50 shuffled copies** of the genome (fixed seed, base composition preserved), then re-run **Step 2 unchanged** on each one. The structural-search hits recovered there are the **decoys**: 13 in total, or **0.26 per randomized genome** (95% CI 0.14–0.44). They are in `tRNA13_RANDOM_SEQUENCE_2` and `tRNA_random_13_positions_1-72`; the per-genome counts are in S3 (sheet *Randomised_Genomes*).

### Stage II: probabilistic score

**Step 4: Build the reference model.** The model uses the **positional A/C/G/U composition of the 199 reference tRNAs** on Sprinzl positions 1–72 (`tRNA_Database_T_Psi_C_199_1`; sequences in `trna_data_rev3_199_tpsic`). Emission and transition probabilities use add-one smoothing (S1, sheets *Formulas*, *Emission Matrix*, *Transition Prob Matrices*).

**Step 5: Score all sequences and set the threshold.** Score the reference tRNAs (leave-one-out), the 158 held-out known tRNAs, the 960 base-shuffled tRNAs, the decoys and the candidates. The threshold is set midway between the highest decoy score (−0.1890) and the weakest held-out known tRNA (+0.0288), giving **τ = −0.0801**. All scores are in `Supplementary_Data_S1_tRNA_validation_REV3_199_R2`; the combined candidate-plus-decoy table is `TOTAL_CANDIDATE_RANDOM_TRUE`.

### Stage III: GC criteria

**Step 6: Apply the G+C criteria.** Compute overall GC, G+C in the 42 stem positions and dGC for each sequence (positions 1–72, missing positions excluded), as in SET V. Apply the three criteria, the 5th percentiles of the 199 reference tRNAs:

| Criterion | Threshold |
|---|---|
| C1: overall GC | ≥ 49.2% |
| C2: GC_stem | ≥ 24 of 42 stem positions (57.1%) |
| C3: dGC = GC_stem − GC_nonstem | ≥ +14.9 percentage points (positive = GC-rich stems) |

Cross-check against `tRNA_GC_dGC_Summary_for_REV3` and the sheets *GC_Criteria* and *GC_Reference_Stats* of `Final_Validation_Status_tRNA_candidates_R2`.

### Final decision

**Step 7: Read off the final status.** Apply the decision rule (Section 7). The status of each candidate and decoy is in `Final_Validation_Status_tRNA_candidates_R2` (S3, sheets *Final_Status* and *Stage_Results*), with supporting detail in S1. The manuscript tables are in `Manuscript_Tables_3-6_FINAL`. To check any number quoted in the manuscript, open `Manuscript_Value_Verification`.

**Reference checkpoints.** Every intermediate output above has a committed counterpart in this repository, so each stage can be checked on its own rather than only at the end.

---

## 6. Results

| Stage | Output | Candidates (MBSW genome) | Decoys (50 randomized genomes) |
|---|---|---|---|
| **I** | Structural-search hits | 9 | 13 (0.26 per genome) |
| **II** | Score ≥ τ / above every decoy / within decoy range | 1 / 1 / 7 | 0 / 0 / 13* |
| **III** | Meet all three / one or two / no GC criteria | 1 / 1 / 7 | 0 / 0 / 13 |
| **Final** | Supported / borderline / not supported | 1 / 1 / 7 | 0 / 0 / 13 |

\*By construction, because τ was calibrated on the decoys.

| Outcome | Candidate(s) | Why |
|---|---|---|
| **Supported** (putative split tRNA) | `trna64` (UCA anticodon) | S = +0.0394, above the threshold and within the range of known tRNAs; meets all 3 GC criteria (GC 64.8%, GC_stem 34/42, dGC +39.6). Its halves lie 39 nt apart at the 37/38 (intron) position |
| **Borderline** | `trna958` (CUA anticodon) | S = −0.1423, above every decoy but below the threshold; meets 0 of 3 GC criteria. Its halves lie 3.22 Mb apart |
| **Not supported** | `trna1091`, `trna1395`, `trna1`, `trna20`, `trna9`, `trna590`, `trna1470` | Scores within the decoy range (−0.2388 to −0.4932) |

Key numbers:

- **Separation from controls:** known tRNAs vs decoys and vs base-shuffled tRNAs, complete separation (AUC = 1.000).
- **Candidates vs decoys:**
  - the score S alone discriminates weakly (AUC 0.615);
  - GC features discriminate better (AUC up to 0.897 for the three combined);
  - adding S **lowers** every GC AUC, so GC, not the score, provides this discrimination.
- **G+C criteria:** accept 92–98% of known tRNAs and **0 of 13** decoys (no decoy meets even one criterion).
- **Decoys retained:** 0.26 per randomized genome after Stage I, 0 after Stage III.
- **Robustness:** trna64 is supported under every version of the rule tested, and under GC thresholds from the 1st to the 10th percentile.
- **Power limit:** with 13 decoys the smallest attainable p value is 1/14 = 0.071.

---

## 7. Decision rule

| Stage | What it is | Role in the decision |
|---|---|---|
| **Stage I** | Structural search (cloverleaf, conserved positions, tertiary interactions, anticodon, BHB) | **Entry filter.** Stem pairing, conserved positions and T-loop match are then reported but not used in the decision |
| **Stage II** | Position-specific probabilistic score S, **decoy-calibrated** | **Necessary condition:** a tRNA-like positional sequence pattern |
| **Stage III** | **G+C criteria** (C1–C3) derived from the reference tRNAs only | **Additional requirement:** GC-rich stems for stable pairing |

**Decision rule** (fixed before it was applied):

- **Supported:** S ≥ τ (−0.0801) **and** all three G+C criteria met.
- **Borderline:** S above every decoy, but not supported.
- **Not supported:** S within the decoy range, whatever the G+C profile.

G+C is an **additional requirement only**; it is never used to rescue a candidate whose score lies in the decoy range.

---

## 8. Notes on methodology

- **The 37/38 join point is fixed, not fitted.** It is the normal intron position in archaeal tRNAs and the position at which real split tRNAs are joined. **No alternative join position was used.**
- **Decoys come from the same search.** The randomized genomes are processed by the *identical* code path, so the decoys reflect the method itself, not a separate approximation.
- **Held-out validation sets.** **VAL1** (same-species tRNAs) and **VAL2** (further T-psi-C tRNAs) were **held out of REF** and never contributed to the model.
- **VAL1 is not a gold standard.** The 62 *M. barkeri* tRNAs are tRNAscan-SE computational annotations, not experimentally confirmed tRNAs; they serve as an organism-specific reference distribution.
- **G+C thresholds were not tuned on the result.** They are the 5th percentiles of the 199 reference tRNAs; candidates and decoys were not used to set them.
- **Limits of the randomized-genome control.** Shuffling preserves base composition but not dinucleotide frequencies, local GC variation or repeats. The decoys are AT-rich (mean GC 31.3%). A larger, GC-matched decoy set would be a stronger test.
- **Anticodon labels are not functions.** "Sec" (UCA) and "Sup" (CUA, UUA) refer only to the anticodon class.
- **Comparison with conventional annotation.** No selenocysteine or possible suppressor tRNA is annotated for this genome in GtRNAdb (tRNAscan-SE). That tool searches contiguous regions and is not designed to detect tRNAs with separated halves.
- **Computational evidence only.** Transcription, processing of the two halves, aminoacylation and stop-codon suppression of the candidates have not been tested experimentally.
- **Tools used throughout the work.** C programs for the scan and shuffling; spreadsheets for the tabulated calculations (live formulas); programming for the ROC and Mann–Whitney statistics; manual pen-and-paper checks of intermediate results; and AI assistance for checking and correcting results.
- **Spreadsheet compatibility.** All tabulated results are provided as **Excel 2007-compatible** workbooks.

---

## 9. How to cite

If you use this code or data, please cite the accompanying manuscript:(after publication)

> U. Roy Mandal, S. Das and K. Maity. A Position-Specific Probabilistic Model for Computational Screening of Split Suppressor-tRNA Candidates in *Methanosarcina barkeri* strain Wiesmoor. *Journal of Bioinformatics and Computational Biology*, 2026. DOI: [to be added]

---

## 10. Contact

Given the number of files and the range of calculations involved, questions are welcome.

**Email:** [urmandal@gmail.com](mailto:urmandal@gmail.com)

---

<div align="center">

*Split suppressor-tRNA screen · **Methanosarcina barkeri** str. Wiesmoor · Genome accession **CP009526.1***

</div>
