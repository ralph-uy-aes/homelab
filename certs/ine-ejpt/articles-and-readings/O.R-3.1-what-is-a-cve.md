# O.R. 3.1 - What is a CVE?

## Overview

- **CVE (Common Vulnerabilities and Exposures)** – a list of publicly disclosed computer security flaws.
- Each CVE is assigned a unique **CVE ID** (e.g., `CVE-2019-1234567`).
- Developed by **MITRE Corporation** in 1999 as a uniform standard for reporting and tracking software security bugs.
- CVEs help IT professionals coordinate efforts to prioritize and address vulnerabilities.

> **Key Point:** A CVE entry is **brief** – it does NOT include technical data, risks, impacts, or fixes. Those details appear in other databases like the **NVD (National Vulnerability Database)** .

---

## How the CVE System Works

### CVE Numbering Authorities (CNAs)

- Organizations authorized to assign CVE IDs to vulnerabilities.
- Approximately **100 CNAs** exist, including:
  - Security companies
  - Research organizations
  - Major IT vendors: **Red Hat, IBM, Cisco, Oracle, Microsoft**
- MITRE can also issue CVEs directly.

### The CVE Assignment Process

| Step | Description |
|------|-------------|
| **1. Discovery** | Anyone (vendor, researcher, user) discovers a security flaw. |
| **2. Disclosure** | Reported to a CNA or the relevant community (often via bug bounties). |
| **3. Assignment** | CNA assigns a CVE ID (often kept secret until fixes are developed). |
| **4. Publication** | CVE is posted on the CVE website with ID, description, and references. |

### CVE ID Format

```
CVE-YEAR-IDNUMBER
```

**Example:** `CVE-2019-1234567`

---

## What Qualifies as a CVE?

According to CNA operational rules, flaws must meet **three criteria**:

| Criteria | Description |
|----------|-------------|
| **Independently Fixable** | The flaw can be fixed independently of any other bugs. |
| **Acknowledged or Documented** | Vendor acknowledges the bug and confirms negative security impact, OR reporter provides a vulnerability report demonstrating the impact. |
| **Affects Only One Codebase** | If a flaw impacts multiple products, each gets a separate CVE. Shared libraries/protocols get a single CVE only if there's no way to use the shared code without being vulnerable. |

> **Example:** A single complex product (like an OS) can accumulate **hundreds of CVEs** over its lifecycle.

---

## Common Vulnerability Scoring System (CVSS)

- An open standard for assigning a **severity score** to vulnerabilities.
- Scores range from **0.0 to 10.0** – higher numbers = more severe.
- Used by NVD, CERT, and others to assess impact.

### CVSS Severity Ranges

| Score Range | Severity |
|-------------|----------|
| 0.0 – 3.9 | Low |
| 4.0 – 6.9 | Medium |
| 7.0 – 8.9 | High |
| 9.0 – 10.0 | Critical |

---

## Red Hat's Role with CVEs

- Red Hat is a **CNA** and uses CVE IDs to track security vulnerabilities.
- Red Hat Product Security maintains a public, frequently updated database of security updates.
- **Extended Lifecycle Support (ELS)** – addresses CVEs rated Critical or Important for products in end-of-maintenance (e.g., RHEL 7).

> **Red Hat CVE Database:** [https://access.redhat.com/security/cve/](https://access.redhat.com/security/cve/)

### Red Hat Security Data API

- Provides raw security data in **machine-consumable formats** (XML or JSON).
- Includes:
  - OVAL definitions
  - CVRF documents
  - CVE data

---

## Key Takeaways

- **CVE** = a standardized identifier for publicly disclosed security vulnerabilities.
- **CVEs are brief** – they reference, but do not contain, technical details.
- **CNAs** (like Red Hat, Microsoft, Cisco) assign CVE IDs to flaws.
- A flaw must be **independently fixable, acknowledged, and affect one codebase** to qualify as a CVE.
- **CVSS scores** (0.0–10.0) provide a severity rating for prioritizing fixes.
- **Not every CVE applies to every environment** – always validate relevance to your specific OS, applications, and configurations.
- **Vulnerability management** is a repeatable process: identify → classify → prioritize → remediate → mitigate.
- **End-of-life systems** are particularly vulnerable – migrate to supported platforms with regular security patches.

---

## Quick Reference

| Term | Definition |
|------|------------|
| **CVE** | Common Vulnerabilities and Exposures – unique ID for a public security flaw |
| **CNA** | CVE Numbering Authority – organization authorized to assign CVE IDs |
| **NVD** | National Vulnerability Database – contains CVE details, CVSS scores, and impact data |
| **CVSS** | Common Vulnerability Scoring System – 0.0–10.0 severity scoring standard |
| **OVAL** | Open Vulnerability and Assessment Language – machine-readable vulnerability definitions |

> **Defender Mindset:** Regularly monitor CVE databases, validate relevance to your environment, and prioritize remediation based on CVSS scores and organizational risk.