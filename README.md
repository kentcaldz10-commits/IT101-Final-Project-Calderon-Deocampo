## Code Review & Documentation Notes

### AI-Generated Code Patterns (`main.c`)
Parts of `main.c` exhibit structural and stylistic characteristics typical of LLM-assisted code generation, which should be reviewed and refactored for consistency:
* **Boilerplate Formatting & Comments:** Extensive ASCII section dividers (e.g., `// ===...===`) and meta-explanatory comments that echo prompt constraints (e.g., `// Handle menu selection using if-else statements`, `// Mandatory "Try Again" Loop Constraint`).
* **Overly Polished Console UI:** Box-drawn CLI banners, bracketed status badges (`[ PASS ]`, `[Error]`), and context-specific exit messages (`"Good luck with your defense!"`).
* **Inconsistent Input Validation:** While the main menu and initial size prompts validate `scanf` return values and clear the input buffer (`while (getchar() != '\n')`), sub-menu selections, float inputs in the Grade Calculator, and unbounded `scanf("%s", word)` calls in the Palindrome Checker lack proper validation and bounds checking.

### Flowchart & Implementation Inconsistencies (`IT102_Flowcharts_Algorithms_Pseudocode-Final.pdf`)
Several visual and logical discrepancies exist between the documentation flowcharts and the C source code:
* **Main Menu Branch Misalignment:** In the Main Program flowchart, the numeric branch labels (`1`–`5`) under `Is choice 1-5?` do not align with their corresponding module execution boxes (e.g., label `5` sits above Module 3, and label `3` sits above Module 4).
* **Missing Menu Output Step:** The Main Program flowchart begins directly at `Read menu choice` without a preceding `Display Main Menu` output step.
* **Module 1 (Pattern Generator) Label Placement:** In the Module 1 flowchart[cite: 1], the branch labels (`1`–`5`) under `Select pattern` are shifted off-center relative to the arrows leading to each pattern block (e.g., `1` sits over the arrow for `2. Square`, and `3` sits between `2. Square` and `3. Isosceles Triangle`)[cite: 1].
