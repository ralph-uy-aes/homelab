# Common Weakness Enumeration

#### What is CWE
- Common Weakness Enumeration (CWE) is a list of community-developed software and hardware weakness types
- Includes programming errors, design errors, architecture errors, etc... which lead to exploitable vulnerabilities
- Allows developers to identify and minimize weaknesses as early in the lifecycle as possible, improving security and helping prevent vulnerabilities
- Often referred to as the CWE coding standard for convenience, but isn't a coding standard

#### Importance of CWE
- Enhanced Security: Minimizes likelihood of cyberattacks and data breaches
- Reduced Risk: Mitigates financial, regulatory, and reputational damage
- Cost Savings: Fixing vulnerabilities early is cheaper than post-deployment
- Compliance: Demonstrates adherence to regulations (GDPR, HIPAA, PCI DSS)
- Customer Satisfaction and Trust: Builds confidence and competitive advantage
- Faster Time to Market: Avoids delays from late-stage security fixes
- Protection of IP: Safeguards sensitive data and proprietary information

#### MITRE
- Sponsored by DHS CISA which is managed by MITRE via Homeland Security Systems Engineering and Development Institute (HSSEDI)

#### CWE Top 25
- A subset of CWE that highlights the most common and dangerous software weaknesses from the last two years
- Easy to find/exploit (Common) and can lead to data theft or system takeovers (Dangerous)
- Isn't actually 25, but keeps the name

#### CWE vs CVE
- CWE: Lists types of weaknesses (vulnerability types)
- CVE: Lists specific instances of vulnerabilities in actual products (vulnerabilities themselves)

#### NIST 500-268 Relation
- Static analysis implementation standard
- Calls out specific CWE entries to C and C++
- Focuses on stack/heap safety, exceptions, range-based errors

#### CWSS vs CVSS
- Common Weakness Scoring System (CWSS): Scores weaknesses using attack surface, base, environmental metrics, etc...
- Common Vulnerability Scoring System (CVSS): Scores vulnerability instances using base, temporal, environmental metrics, etc...

#### NVD Relation to CVE/CVSS
- National Vulnerability Database (NVD) is managed by NIST, not MITRE
- Enhances CVE list data by adding information like CVSS Base scores
- CVE Feeds into NVD

#### CWE 4.14
- Current version of CWE with 938 weaknesses
- Dynamic, community-improved
- Difference between 4.14 and 3.4:
    - CWE 4.14 includes new weaknesses
        - CWE 3.4.1: 808 weaknesses
        - CWE 4.0: 839 weaknesses
        - CWE 4.14: 938 weaknesses
    - Includes refinements and clarifications to the list

#### CWE Organization
- Organized by abstraction of behavior, not code location
- Tree-like structure:
    - Highest Level: Categories & Pillars (group weaknesses, not weaknesses themselves)
    - Lower Levels: Weaknesses at various abstraction levels

#### CWE Weakness Levels
- Class Level: Broad, fundamental issues with overall software structure
- Base Level: Specific code flaws, easier to spot via code review/automated analysis

#### CWE Compatibility
- Program for products or services to be officially CWE-Compatible & CWE-Effective
- Criteria:
    - CWE Searchable: Users can search using CWE Ids
    - CWE Output: Presents associated CWE IDs
    - Mapping Accuracy: Accurately links to correct CWE IDs
    - CWE Documentation: Describes CWE and how to use related functionality
- LDRA's LDRA Testbed and TBvision are CWE-Compatible

#### LDRA Helping with CWE Compliance
- Provides consultancy and tools in LDRA tool suite and LDRArules
- How it helps:
    - Identify Vulnerabilities: Static analysis scans code against CWE
    - Early Detection: Integrates into SDLC early
    - Comprehensive Testing: Static and dynamic analysis, unit testing
    - Customizable Rule Sets: Tailor to specific CWE rules
    - IDE Integration: Fits into existing workflows
    - Compliance Reporting: Generates adherence reports
    - Training & Support

#### Examples of CWE Rules Found by LDRA Tools
- CWE-787: Out-of-bounds Write
- CWE-416: Use After Free
- CWE-78: OS Command Injection
- CWE-20: Improper Input Validation
- CWE-125: Out-of-bounds Read
- CWE-22: Path Traversal
- CWE-362: Race Condition
- CWE-476: NULL Pointer Dereference

#### LDRA Static Analysis
- Ensures CWE compliance as code is developed
- Automatically applied during unit/system/integration testing
- Function: Locates, highlights, and reports non-conformant code

#### LDRA Dynamic Analysis
- Identifies weaknesses in the executable
- Tools: TBvision, TBrun
- Benefits:
    - Identifies actual runtime vulnerabilities
    - Tests for security misconfigurations
    - Detects runtime flaws
    - Assesses resilience to attacks
    - Supports structural coverage analysis

#### Testing Types
- Unit vs Integration Testing (TBrun)
    - Unit: Tests isolated code (with stubs)
    - Integration: Tests how units work together
- System vs Integration Testing (TBvision/TBrun)
    - Integration/SIT: Focuses on component/subsystem interactions
    - System: Verifies the complete system meets objectives

#### CWE Compliance Tools from LDRA
- TBvision: Automated static code checking & dynamic system testing.
- TBrun: Unit, integration, SIT, and system testing.
- TBextreme: Automated test vector generation.
- LDRArules: Stand-alone rules checker (includes CWE checks).
- TBsecure: Enables CWE reporting, identifies security vulnerabilities.
- TBexclude: Manages justified rule violations.
- TBmanager: Automates requirements traceability.

#### CWE Compliance Matrix
- LDRA provides full transparency on rule compliance
- Matrix shows which CWE rules are implemented/partially implemented
- Excludes rules for unsupported languages, libraries, or non-statically checkable issues
- Most C/C++ related CWE rules are implemented to some degree