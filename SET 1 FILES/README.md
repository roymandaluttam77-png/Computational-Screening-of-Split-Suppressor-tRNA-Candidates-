# Computational Screening of Candidate Split Suppressor-tRNAs in *Methanosarcina barkeri* str. Wiesmoor

A position-specific probabilistic pipeline that scans a complete archaeal genome for **split tRNA genes** — tRNAs stored as two separate halves — joins candidate halves, scores them against a profile built from known tRNAs, and calibrates every score against decoys drawn from shuffled genomes.

This repository contains the **executable source code, input sequences, genome accessions, model and scoring procedures, randomization procedure, candidate reconstruction and filtering steps, and the complete results** — including the predicted candidates, their constituent fragments, and the randomized-genome decoys.

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
9. [Contact](#9-contact)

---

## 1. What problem does this solve?

A normal tRNA gene sits in the genome **in one piece**.

A **split tRNA gene does not**. It is stored as two separate pieces — a **5′ half** and a **3′ half** — sometimes very far apart. The cell transcribes both pieces and joins them afterwards to make one working tRNA.

> Split tRNAs are hard to find, because **neither half looks like a tRNA on its own**. This pipeline looks for them.

**Why a documented implementation matters:** it allows other researchers to verify the results, examine the candidate-selection procedure, and build upon the method.

---

## 2. How does it work?

Six simple steps.

| Step | What happens | Why it matters |
| :--- | :--- | :--- |
| **1. Learn what a real tRNA looks like** | Take **199 known tRNAs**, all lined up at **72 standard (Sprinzl) positions**. At each position, count how often **A, C, G and U** appear. | This gives the *profile* of a typical tRNA. |
| **2. Search the genome for halves** | Slide along **both strands** of the *M. barkeri* genome and note every stretch that looks like a tRNA **5′ half** or a tRNA **3′ half**. | Halves are the only signal available — a split gene has no intact copy. |
| **3. Join the halves** | Pair each 5′ half with each 3′ half and glue them together. The glue point is **always position 37/38**. | **Not a guess.** 37/38 is the normal position where archaeal tRNAs carry introns, and where real split tRNAs are normally joined. **No other join position was ever used.** |
| **4. Score each joined sequence** | Compare it to the profile from Step 1 and assign a score. | A high score means *"this looks like a real tRNA."* |
| **5. Check against fakes** | **Shuffle the genome 50 times** and run the *exact same pipeline* on each shuffled copy. Anything found there is a false positive by definition. | These are the **decoys**, and they set the pass mark. A score is meaningless on its own. |
| **6. Add a G+C-content filter** | Measure G+C in stems versus loops. Real tRNA **stems** are rich in G and C (G–C pairs are stronger than A–U pairs); **loops** are not. | Used as an extra, independent requirement. |

---

## 3. Data sources

| Dataset | Source | Link |
| :--- | :--- | :--- |
| **Genome** — *Methanosarcina barkeri* str. Wiesmoor chromosome, complete genome | NCBI Nucleotide · **ACCESSION NZ_CP009526** | [ncbi.nlm.nih.gov/nuccore/CP009526.1](https://www.ncbi.nlm.nih.gov/nuccore/CP009526.1/) |
| **Reference tRNA set** — 199 known tRNAs | **T-Psi-C** database | [tpsic.igcz.poznan.pl](https://tpsic.igcz.poznan.pl/info/start/) |
| **Same-species known tRNAs** (mature) | **GtRNAdb** — *Meth. barkeri* Wiesmoor | [gtrnadb.org](https://gtrnadb.org/genomes/archaea/Meth_bark_Wiesmoor/) |

---

## 4. Repository contents

Files are grouped into six sets. In every table, the **description is on the left** and the ***file name is on the right***.

### SET I — Genome scan and structural filters

| # | Description | File |
| :-- | :--- | ---: |
| 1 | *M. barkeri* str. Wiesmoor chromosome, complete genome — accession **NZ_CP009526** | ***see [Data sources](#3-data-sources)*** |
| 2 | Input sequence | ***input.txt*** |
| 3 | Output — base pairs of nucleotides | ***output_base_pair*** |
| 4 | Output — tRNA secondary structure (9 candidates) | ***output_tRNA_2D_Structure*** |
| 5 | Flow diagram of the two-phase pipeline with G+C filter | ***tRNA_two_phase_flow_diagram_GC*** |
| 6 | Pseudocode — Phase I, Phase II and G+C filter | ***Split_tRNA_pseudocode_PhaseI_PhaseII_GC*** |
| 7 | **Demo source code (C)** — genome scan and structural filters | ***split2_trna_added_371.c*** |
| 8 | **Genome shuffler (C)** — generates the randomized genomes for decoys | ***random1.c*** |

### SET II — tRNA database, random-genome candidates and predicted candidates *(sequence + dot-bracket)*

| # | Description | File |
| :-- | :--- | ---: |
| 9 | **REF** — reference set of known tRNAs, from the T-Psi-C database | ***trna_data_rev3_199_tpsic*** |
| 10 | **VAL1** — known tRNAs of the same species (mature), **held out of REF** | ***tRNA__tRNAScan_MBSW_1*** |
| 11 | **VAL2** — further known tRNAs from the reference database, **held out of REF** | ***random_99_T_psi_c_trna*** |
| 12 | **DECOY** — candidates recovered from the shuffled genomes | ***tRNA_RANDOM_SEQUENCE_2*** |
| 13 | **CAND** — predicted candidates to validate | ***Candidate9_FASTA_SEQUENCE_Withdot*** · ***candidate_tRNA_9*** |

### SET III — The position-specific profile *(Sprinzl positions 1–72)*

At each position, counts of **A, C, G and U** across positions **1–72**.

| # | Description | File |
| :-- | :--- | ---: |
| 14 | Reference set — **199 known tRNAs** on Sprinzl positions 1–72 | ***tRNA_Database_T_Psi_C_199_1*** |
| 15 | Same-species known tRNAs (mature) on positions 1–72, held out of REF | ***tRNA__tRNAScan_MBSW_62_2*** |
| 16 | Further known tRNAs from the reference database on positions 1–72, held out of REF | ***tRNA_T_Psi_C_99_OTHER*** |
| 17 | Candidates from the **shuffled genomes** on positions 1–72 | ***tRNA_random_13_positions_1-72*** |
| 18 | **Predicted candidates** on positions 1–72, to validate | ***candidate_tRNA_3*** |
| 19 | **Combined (17 + 18)** candidates on positions 1–72, to validate | ***TOTAL_CANDIDATE_RANDOM_TRUE*** |

### SET IV — Structural and probabilistic assessment

| # | Description | File |
| :-- | :--- | ---: |
| 20 | **S1** — structural and probabilistic assessment of the nine predicted split-tRNA candidates | ***Supplementary_Data_S1_tRNA_validation_REV2*** |
| 21 | Validation of the **9 predicted candidates against a realistic negative control** | ***tRNA_v6_Final_Validation_Excel2007_REV2*** |

### SET V — G+C distribution in tRNA stems vs non-stem regions

Each file reports G+C content for the **whole tRNA sequence**, the **4 stems + 3D base pairs**, and the **4 loops**.

| # | Dataset | File |
| :-- | :--- | ---: |
| 22 | **S2** — T-Psi-C database tRNAs | ***TpsiC_199_tRNA_GC_content_stems_3D_loops_Dgc*** |
| 23 | *M. barkeri* str. Wiesmoor (**MBSW**) genomic tRNAs | ***MBSW_tRNA_GC_content_stems_3D_loops_v2_dGC*** |
| 24 | T-Psi-C database tRNAs (**99**) | ***TpsiC_tRNA_GC_content_stems_3D_loops_dGC*** |
| 25 | **Random** tRNA candidates (decoys) | ***Random_tRNA_GC_content_stems_3D_loops_dGC*** |
| 26 | **Validated candidates** | ***tRNA_GC_content_stems_3D_loops_dGC*** |
| 27 | **Summary** — G+C distribution in stems vs non-stem regions, all datasets compared | ***tRNA_GC_dGC_Summary_for_REV3*** |

### SET VI — Final validation status

| # | Description | File |
| :-- | :--- | ---: |
| 28 | **Final validation status** of the 9 predicted split suppressor-tRNA candidates (*M. barkeri* str. Wiesmoor) | ***Final_Validation_Status_tRNA_candidates*** |

---

## 5. Reproducing the analysis

### Requirements

* A **C compiler** (`gcc` or any C99-compatible compiler) — for ***split2_trna_added_371.c*** and ***random1.c***
* A **spreadsheet application** — the tabulated results are supplied in **Excel 2007-compatible** workbooks
* The genome sequence for accession **NZ_CP009526**, prepared as ***input.txt***

### Step-by-step

**Step 1 — Get the genome.**
Download the complete chromosome of *M. barkeri* str. Wiesmoor from [NCBI accession CP009526.1](https://www.ncbi.nlm.nih.gov/nuccore/CP009526.1/) and place the sequence in ***input.txt***, in the format used by the supplied copy of that file.

**Step 2 — Build the reference profile.**
The profile is the **positional A/C/G/U composition of 199 known tRNAs** aligned on Sprinzl positions 1–72, as tabulated in ***tRNA_Database_T_Psi_C_199_1*** (sequences in ***trna_data_rev3_199_tpsic***).

**Step 3 — Run the genome scan and structural filters.**

```bash
gcc -O2 -o split2_trna split2_trna_added_371.c
./split2_trna
```

This performs the half-search on **both strands**, the **37/38 reconstruction**, the genome scanning and the structural filters. Compare against the supplied ***output_base_pair*** and ***output_tRNA_2D_Structure***.

**Step 4 — Generate the randomized genomes (decoys).**

```bash
gcc -O2 -o random1 random1.c
./random1
```

Produce **50 shuffled copies** of the genome, then re-run **Step 3 unchanged** on each one. Candidates recovered here are false positives by construction; they are the decoy set in ***tRNA_RANDOM_SEQUENCE_2*** and ***tRNA_random_13_positions_1-72***.

**Step 5 — Calibrate the pass mark.**
Use the decoy score distribution to set the threshold, then apply it to the real-genome candidates. The calibrated comparison is in ***tRNA_v6_Final_Validation_Excel2007_REV2***, with the combined true-plus-decoy table in ***TOTAL_CANDIDATE_RANDOM_TRUE***.

**Step 6 — Apply the G+C criteria.**
Compute G+C for the whole sequence, the **4 stems + 3D base pairs**, and the **4 loops**, following the definition used in SET V. Cross-check against ***tRNA_GC_dGC_Summary_for_REV3***.

**Step 7 — Read off the final status.**
Candidate-by-candidate outcomes are in ***Final_Validation_Status_tRNA_candidates***, with supporting detail in ***Supplementary_Data_S1_tRNA_validation_REV2***.

> **Reference checkpoints.** Every intermediate output above has a committed counterpart in this repository, so each stage can be verified independently rather than only at the end.

---

## 6. Results

Nine candidates were predicted and carried through all three assessment stages.

| Outcome | Candidate |
| :--- | :--- |
| **Supported** | ***trna64*** |
| **Borderline** | ***trna958*** |

Of the **9 candidates**, **trna64 is supported** and **trna958 is borderline**, after considering all three stages below.

---

## 7. Decision framework (Stages A, B, C)

| Stage | What it is | Role in the decision |
| :--- | :--- | :--- |
| **Stage A** | Position-specific probabilistic model, **decoy-calibrated** | **Decisive** |
| **Stage B** | Structural features | **Reported, but not used in the decision** |
| **Stage C** | **G+C composition criteria** derived from the reference tRNAs | **Decisive** |

**G+C definition.** G+C follows the definition of the original supplement: **canonical slots 1–72, with missing slots excluded**.

---

## 8. Notes on methodology

* **The 37/38 join point is fixed, not fitted.** It is the normal intron position in archaeal tRNAs and the position at which real split tRNAs are joined. **No alternative join position was used.**
* **Decoys come from the same pipeline.** The shuffled genomes are processed by the *identical* code path, so the null distribution reflects the method itself, not a separate approximation.
* **Held-out validation sets.** **VAL1** (same-species mature tRNAs) and **VAL2** (further reference tRNAs) were **held out of REF** and never contributed to the profile.
* **Tooling used throughout the work.** C programs for the scan and shuffling; spreadsheets for the tabulated calculations; manual pen-and-paper checks of intermediate results; and AI assistance for checking and correcting results.
* **Spreadsheet compatibility.** Tabulated results are provided in **Excel 2007-compatible** workbooks.

---

## 9. Contact

Given the number of files and the range of calculations involved, questions are welcome.

**Email:** urmandal@gmail.com

---

<div align="center">

*Split suppressor-tRNA screen · **Methanosarcina barkeri** str. Wiesmoor · Genome accession **NZ_CP009526***

</div>
