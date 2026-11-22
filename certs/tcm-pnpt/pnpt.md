# PNPT Study Timeline: Nov 2026 to Apr 2027

**Goal:** pass the TCM Security PNPT on the first attempt. **Official start:** Sunday, November 22, 2026. **Exam target:** Monday, April 12, 2027, with April 19–30 held as buffer. **Starting point:** eJPT done, Active Directory brand new. **Schedule:** Saturday and Sunday, after your 8am–4pm security shift, starting 4:30 pm. Through Jan 31: 6 hours of training (4:30–11:00 pm). From Feb 6: 8 hours (4:30 pm–12:30 am). Weekdays are optional from Feb 1.

Tick each box as you finish it. Every task has a time box and, where one exists, a link.

## How the exam works (plan around it)

- 5 days of hands-on testing against a simulated corporate network (external recon and OSINT, then AD compromise ending at the domain controller).
- 2 days to write a professional report.
- A 15-minute live debrief in front of senior pentesters.
- The voucher includes the training and is valid for 12 months. Confirm current price, retake terms and scheduling on the [PNPT page](https://certifications.tcm-sec.com/pnpt/) before buying.

**Time off:** the exam week is 7 consecutive days (Apr 12–18). Request leave from both jobs by **Feb 1**. Lock the exam date with TCM as soon as you buy the voucher so the deadline is external, not self-set.

## Blocked dates

- **Sat Dec 26 and Sun Dec 27:** California trip, no study.
- Dec 19–20 stay on. If the trip starts earlier, or the December Japan trip overlaps any other weekend, tell Claude and those days get cut and the plan re-cut.

## The four phases

| Phase | Dates | Study days | Focus |
| --- | --- | --- | --- |
| 0. Foundations | Nov 22 – Jan 31 | 19 days, 6 h each | Networking, AD fundamentals, pivoting, privesc |
| 1. TCM core | Feb 6 – Feb 28 | 8 days, 8 h each | Practical Ethical Hacking, AD attacks, privesc courses |
| 2. Engagement skills | Mar 6 – Mar 28 | 8 days, 8 h each | OSINT, external playbook, AD boxes, mock exam 1 |
| 3. Rehearsal and taper | Apr 3 – Apr 11 | 2 full days, then light | Mock exam 2, report, debrief |
| Exam | Apr 12 – Apr 18 | n/a | 5 days testing, 2 days report |

Default exam date stays April 12; decide after Mock 1 (Mar 27–28) whether to pull it earlier.

## Rules that make this work

1. **Daily shape.** Learn, then hands-on, then a 1-hour write-up, with a 30-minute break around 7:00 pm. Notes are passive: type them as you learn, with no separate notes block. They feed one AD attack cheat sheet that becomes your exam playbook.
2. **Write-up hour (publishable).** Every day ends with a 1-hour practice report in the style of the [TCM sample report](https://github.com/hmaverickadams/TCM-Security-Sample-Pentest-Report), saved to a public GitHub repo (`pnpt-prep-writeups`). Sanitize before you push: no flags or room answers, no passwords or hashes, no real IPs outside the lab. Only retired HTB machines. Never post anything about the actual PNPT exam environment.
3. **Energy rule.** If energy drops below about 50%, swap hands-on for review; don't grind through it.
4. **Sunday cutoff.** From Feb 6 the day runs to 12:30 am. If Monday needs you sharp, move that Sunday's write-up hour to Monday or Tuesday evening and end at 11:30 pm.
5. **Repeat until clean.** Redo any lab you needed hints for until you can do it with no help and no notes.
6. **Weekly checkpoint.** At the end of each Sunday, have Claude quiz you on that weekend. Under \~80%: repeat the weak part before moving on.
7. **Try first, then hint.** 30 minutes alone, then a hint, then a writeup.
8. **Access check.** Several rooms are marked Premium (Breaching Active Directory, Exploiting Active Directory, Wreath) and retired HTB machines need VIP. Check each on its page before the day it's scheduled; the plan names a fallback where one exists.

## Materials

- **TryHackMe modules:** [Networking](https://tryhackme.com/module/networking), [Windows Fundamentals](https://tryhackme.com/module/windows-fundamentals), [Active Directory Security Testing Basics](https://tryhackme.com/module/active-directory-security-testing-basics), [Privilege Escalation](https://tryhackme.com/module/privilegeescalation), [Pentesting Methodologies and Reporting](https://tryhackme.com/module/pentesting-methodologies-and-reporting).
- **TCM:** [Practical Ethical Hacking course](https://academy.tcm-sec.com/p/practical-ethical-hacking-the-complete-course), the free [15-hour version on freeCodeCamp](https://www.freecodecamp.org/news/full-penetration-testing-course), [Windows Privilege Escalation for Beginners](https://classcentral.com/classroom/youtube-windows-privilege-escalation-for-beginners-182503) and [Linux Privilege Escalation for Beginners](https://classcentral.com/course/youtube-linux-privilege-escalation-for-beginners-179900) (both Cyber Mentor on YouTube).
- **Previous passers' notes:** [ciwen3/PNPT](https://github.com/ciwen3/PNPT), [TrshPuppy/PNPT-study-guide](https://github.com/TrshPuppy/PNPT-study-guide), [AD Exploitation Cheat Sheet](https://github.com/S1ckB0y1337/Active-Directory-Exploitation-Cheat-Sheet), and a Jan 2026 passer's guide: [How to pass the PNPT (2026)](https://dev.to/mr-3/how-to-pass-the-pnpt-2026-3n6f).
- **Tools:** [NetExec docs](https://www.netexec.wiki/) and a [NetExec cheat sheet](https://github.com/seriotonctf/cme-nxc-cheat-sheet).
- **Walkthroughs after you try a box:** IppSec's videos on YouTube and [0xdf's writeups](https://0xdf.gitlab.io).

## Documentation system

Your report depends on your notes, so set this up before Day 1.

- **Notes:** one Obsidian vault (or any markdown app) with `courses/`, `labs/` and `cheatsheet/` folders. Notes are passive while you learn; the cheat sheet is the only note you rewrite on purpose.
- **Cheat sheet entry:** attack name, when to use it, tool and exact command, why it works, how to fix it. The fix line feeds the remediation section of every report.
- **Command log:** for every lab, record target, open ports, services, credentials found, attack path and screenshots. In the exam, log in real time.
- **Tracker (optional):**

| Date | Day | Room or box | Topic | Status | Key commands | Gaps |
| --- | --- | --- | --- | --- | --- | --- |
| Nov 22 | 1 | Wireshark: The Basics | Packet capture | Done | tcpdump, display filters | Practice filters |

## Tips from a Jan 2026 passer

One person's account; check anything exam-specific against your own Rules of Engagement.

- Finish every TCM course and take the capstones seriously. Learn NetExec well.
- After the exam VPN or an environment reset, he waited 15 minutes before starting. Reset the environment often when something behaves oddly.
- Try each command 3 times before dropping it. After each success, screenshot and note it, then try the other attacks before going deep on the first one.
- Boxes he recommends: HTB Sauna (priority), Cicada, EscapeTwo, Support, Timelapse, Return, Administrator, plus TryHackMe Wreath for pivoting.
- Report format: separate External and Internal sections, TCM's finding template, evidence screenshots. Debrief deck: intro, contents, attack overview, attacks and impacts, remediation plan.

## Exam-day principles

- **Enumeration is everything.** If you're stuck, you've probably missed something: re-enumerate every host and every credential you hold.
- **It's not a CTF.** A [Black Hills InfoSec review](https://www.blackhillsinfosec.com/?p=25002) advises following a rabbit hole for only a few hours before moving on; the exam emulates a small real-world AD environment.
- **Know two ways to pivot.** Be comfortable with at least two of sshuttle, proxychains and chisel, so one failing doesn't stop you.
- **Document in real time.** Screenshot every critical step as it happens.
- **The report can fail you.** Owning the domain controller is not enough; use the TCM template and cover the key findings well.
- **The debrief is a conversation.** You did the work; explain it clearly.
- **No guarantees.** This plan raises your odds; it does not promise a pass.

---

# Phase 0: Foundations (Nov 22 – Jan 31)

6 hours each day, clock 4:30–11:00 pm (including a 30-minute break). Take passive notes during every Learn block.

### Sun Nov 22 · Day 1 · Networking refresher

- [ ] Learn (2 h): [Networking Concepts](https://tryhackme.com/room/networkingconcepts) and [Networking Essentials](https://tryhackme.com/room/networkingessentials)
- [ ] Hands-on (3 h): [Wireshark: The Basics](https://tryhackme.com/room/wiresharkthebasics) and [Tcpdump: The Basics](https://tryhackme.com/room/tcpdump), then capture your own traffic and identify the TCP handshake, DNS, ARP and SMB
- [ ] Write-up (1 h): create the GitHub repo `pnpt-prep-writeups` with a README, `/templates`, `/writeups` and a sanitization checklist; copy the structure of the TCM sample report

### Sat Nov 28 · Day 2 · Scanning and enumeration

- [ ] Learn (2 h): [Networking Core Protocols](https://tryhackme.com/room/networkingcoreprotocols) and [Nmap: The Basics](https://tryhackme.com/room/nmap)
- [ ] Hands-on (3 h): [Basic Pentesting](https://tryhackme.com/room/basicpentestingjt): full Nmap, service enumeration, get a user shell; no hints for the first 30 minutes
- [ ] Write-up (1 h): enumeration findings from Basic Pentesting in TCM format, no flags

### Sun Nov 29 · Day 3 · Windows basics

- [ ] Learn (2 h): [Windows Fundamentals 1](https://tryhackme.com/room/windowsfundamentals1xbx), [2](https://tryhackme.com/room/windowsfundamentals2x0x) and [3](https://tryhackme.com/room/windowsfundamentals3xzx)
- [ ] Hands-on (3 h): in a Windows VM, practice whoami /all, net user, net localgroup, systeminfo, ipconfig /all and basic PowerShell navigation
- [ ] Write-up (1 h): executive summary, scope and methodology sections for a fictional engagement

### Sat Dec 5 · Day 4 · AD concepts

- [ ] Learn (3 h): [Active Directory Basics](https://tryhackme.com/room/winadbasicsrevamp) and [Intro to AD Authentication](https://tryhackme.com/room/introtoactivedirectoryauthentication)
- [ ] Hands-on (2 h): redraw the AD map from memory (domain, DC, OUs, GPOs, users, groups, trusts); write the Kerberos and NTLM flows on paper; redo the room tasks without hints
- [ ] Write-up (1 h): AD environment overview section

### Sun Dec 6 · Day 5 · Your first AD attack

- [ ] Learn (2 h): [Intro to AD Breaching](https://tryhackme.com/room/introductiontoactivedirectorybreaching)
- [ ] Hands-on (3 h): [Attacktive Directory](https://tryhackme.com/r/room/attacktivedirectory): Kerbrute user enumeration, AS-REP roasting, SMB shares, secretsdump
- [ ] Write-up (1 h): AS-REP roasting finding (description, impact, evidence, remediation)

### Sat Dec 12 · Day 6 · AD enumeration

- [ ] Learn (3 h): [AD: Basic Enumeration](https://tryhackme.com/room/adbasicenumeration) and [AD: Authenticated Enumeration](https://tryhackme.com/room/adauthenticatedenumeration)
- [ ] Hands-on (2 h): redo Attacktive Directory with no walkthrough
- [ ] Write-up (1 h): information exposure through domain enumeration finding

### Sun Dec 13 · Day 7 · Credentials and BloodHound

- [ ] Learn (2 h): [Intro to Credential Harvesting](https://tryhackme.com/room/introtocredentialharvesting)
- [ ] Hands-on (3 h): run BloodHound against whichever lab gave you a domain account and find the shortest path to Domain Admin; read the [NetExec docs](https://www.netexec.wiki/) and run the smb and ldap commands from the [cheat sheet](https://github.com/seriotonctf/cme-nxc-cheat-sheet)
- [ ] Write-up (1 h): credential exposure finding

### Sat Dec 19 · Day 8 · Breaching AD

- [ ] Learn (3 h): [Breaching Active Directory](https://tryhackme.com/room/breachingad) (Premium, listed at 120 min), all tasks
- [ ] Hands-on (2 h): repeat the credential-capture and relay tasks with no hints
- [ ] Write-up (1 h): LLMNR/NBT-NS poisoning and relay finding

### Sun Dec 20 · Day 9 · Exploiting AD

- [ ] Learn (2 h): [Exploiting Active Directory](https://tryhackme.com/room/exploitingad) (Premium, 120 min): permission delegation, Kerberos delegation, automated relays, AD users, GPOs, certificates, domain trusts
- [ ] Hands-on (3 h): redo the delegation, relay and GPO tasks with no hints
- [ ] Write-up (1 h): delegation or GPO abuse finding

### Sat Dec 26 and Sun Dec 27 · Blocked (California)

No study. Rest.

### Sat Jan 2 · Day 10 · AD lateral movement

- [ ] Learn (2 h): [Intro to AD Lateral Movement](https://tryhackme.com/room/introductiontoadlateralmovement): PsExec, WinRM, pass-the-hash, SSH tunnels
- [ ] Hands-on (3 h): repeat each technique with Impacket and then with NetExec
- [ ] Write-up (1 h): lateral movement via pass-the-hash finding

### Sun Jan 3 · Day 11 · AD challenges

- [ ] Learn (2 h): NetExec deep dive: smb, ldap and winrm sections of the [docs](https://www.netexec.wiki/), spraying and Kerberoasting commands in the [cheat sheet](https://github.com/seriotonctf/cme-nxc-cheat-sheet)
- [ ] Hands-on (3 h): [Proxy challenge](https://tryhackme.com/room/proxychallenge), then [Forward challenge](https://tryhackme.com/room/forwardchallenge)
- [ ] Write-up (1 h): mini engagement report on the Proxy challenge

### Sat Jan 9 · Day 12 · Wreath, part 1 (pivoting)

- [ ] Learn (2 h): [Wreath](https://tryhackme.com/room/wreath) tasks 1–6: access the network, web server enumeration and exploitation. Premium; a 7-day streak also unlocks it per the passer's guide
- [ ] Hands-on (3 h): Wreath tasks 7–16: pivoting with Proxychains and FoxyProxy, SSH tunnelling, plink, socat, chisel and sshuttle; use every method at least once
- [ ] Write-up (1 h): pivoting methods, with a network diagram and the commands that worked

### Sun Jan 10 · Day 13 · Wreath, part 2

- [ ] Learn (1 h): Wreath tasks 17–19: git server enumeration, pivoting and code review
- [ ] Hands-on (4 h): Wreath tasks 17–21: git server exploitation and stabilization. Tasks 22–38 (C2 and AV evasion) are optional
- [ ] Write-up (1 h): Wreath as a pentest report

### Sat Jan 16 · Day 14 · Windows privilege escalation

- [ ] Learn (3 h): TCM [Windows Privilege Escalation for Beginners](https://classcentral.com/classroom/youtube-windows-privilege-escalation-for-beginners-182503)
- [ ] Hands-on (2 h): [Windows Privilege Escalation](https://tryhackme.com/room/windowsprivesc20)
- [ ] Write-up (1 h): Windows privesc finding (unquoted service path or stored credentials)

### Sun Jan 17 · Day 15 · Linux privilege escalation

- [ ] Learn (2 h): [Linux Privilege Escalation: Basics](https://tryhackme.com/room/linprivbasics)
- [ ] Hands-on (3 h): [Linux Privilege Escalation: Enumeration](https://tryhackme.com/room/linprivenum) and [Automation](https://tryhackme.com/room/linprivautomation)
- [ ] Write-up (1 h): Linux privesc finding (SUID or sudo misconfiguration)

### Sat Jan 23 · Day 16 · Consolidation, part 1

- [ ] Learn (1 h): reread your cheat sheet; list every command you can't explain
- [ ] Hands-on (4 h): [Windows Jump](https://tryhackme.com/room/windowsjump) and [Jump](https://tryhackme.com/room/jump) challenges
- [ ] Write-up (1 h): one challenge in report format

### Sun Jan 24 · Day 17 · Consolidation, part 2

- [ ] Hands-on (4 h): HTB Sauna (retired, needs VIP), 30 minutes with no hints before any hint. No VIP: redo the Forward challenge instead
- [ ] Learn (1 h): watch IppSec's Sauna video and read the 0xdf writeup after you finish
- [ ] Write-up (1 h): Sauna in report format, no passwords

### Sat Jan 30 · Day 18 · Self-test

- [ ] Hands-on (4 h): timed run on HTB Timelapse (retired, needs VIP) using only your cheat sheet. No VIP: a THM AD challenge you haven't seen
- [ ] Learn (1 h): study every gap the run exposed
- [ ] Write-up (1 h): report on the self-test

### Sun Jan 31 · Day 19 · Decision day

- [ ] Hands-on (3 h): fix the gaps from the self-test
- [ ] Admin (1 h): buy the PNPT voucher and training, confirm the exam date, request leave for Apr 12–18
- [ ] Learn (1 h): install and skim the PEH course outline; plan the Feb 6 start
- [ ] Write-up (1 h): clean up the README index of all write-ups and push to GitHub

---

# Phase 1: TCM core (Feb 6 – Feb 28)

8 hours each day, clock 4:30 pm–12:30 am (7.5 h of work plus a 30-minute break): Learn 2.5 h, Hands-on 4 h, Write-up 1 h. Weekdays optional: 20 minutes of cheat sheet review. Course names follow TCM's [Practical Ethical Hacking](https://academy.tcm-sec.com/p/practical-ethical-hacking-the-complete-course); section titles may differ slightly. You already have eJPT, so play early sections at 1.5x.

### Sat Feb 6 · Day 20 · PEH part 1

- [ ] Learn (2.5 h): PEH networking refresher, scanning and enumeration sections
- [ ] Hands-on (4 h): the course's walkthrough boxes plus your own scans; no hints for 30 minutes
- [ ] Write-up (1 h): external service enumeration finding

### Sun Feb 7 · Day 21 · PEH part 2

- [ ] Learn (2.5 h): PEH exploitation basics
- [ ] Hands-on (4 h): the mid-course capstone; treat it like an engagement and screenshot as you go
- [ ] Write-up (1 h): capstone as a short report

### Sat Feb 13 · Day 22 · Build your AD lab

- [ ] Learn (2.5 h): PEH Active Directory overview and lab build sections
- [ ] Hands-on (4 h): build the AD lab: a Windows Server DC and two Windows clients in VMs from evaluation ISOs
- [ ] Write-up (1 h): lab architecture overview

### Sun Feb 14 · Day 23 · Initial attack vectors

- [ ] Learn (2.5 h): PEH AD initial attack vectors: LLMNR poisoning, SMB relay, IPv6 (mitm6)
- [ ] Hands-on (4 h): run each attack in your lab, then crack the captured hashes
- [ ] Write-up (1 h): LLMNR poisoning finding in TCM format (IPT-001)

### Sat Feb 20 · Day 24 · Post-compromise

- [ ] Learn (2.5 h): PEH post-compromise enumeration (ldapdomaindump, BloodHound) and post-compromise attacks (pass-the-hash, token impersonation, Kerberoasting)
- [ ] Hands-on (4 h): run each in your lab
- [ ] Write-up (1 h): Kerberoasting finding

### Sun Feb 21 · Day 25 · More AD attacks

- [ ] Learn (2.5 h): PEH GPP, Mimikatz, additional AD attacks and post-exploitation
- [ ] Hands-on (4 h): redo Saturday's attacks from your cheat sheet only, then repeat each with NetExec where possible
- [ ] Write-up (1 h): attack narrative from first foothold to Domain Admin

### Sat Feb 27 · Day 26 · Windows privilege escalation

- [ ] Learn (2.5 h): TCM Windows Privilege Escalation course
- [ ] Hands-on (4 h): the course labs and capstone
- [ ] Write-up (1 h): one privesc finding in report format

### Sun Feb 28 · Day 27 · Linux privilege escalation and gate

- [ ] Learn (2.5 h): TCM Linux Privilege Escalation course
- [ ] Hands-on (2.5 h): the course labs
- [ ] Gate (1.5 h): checkpoint quiz with Claude; need 80%+ before Phase 2
- [ ] Write-up (1 h): one finding in report format

---

# Phase 2: Engagement skills (Mar 6 – Mar 28)

Same 8-hour shape as Phase 1.

### Sat Mar 6 · Day 28 · OSINT

- [ ] Learn (2.5 h): TCM OSINT Fundamentals
- [ ] Hands-on (4 h): OSINT on a practice target: staff names, email formats, breached credentials; build a username list
- [ ] Write-up (1 h): OSINT findings section

### Sun Mar 7 · Day 29 · External pentest

- [ ] Learn (2.5 h): TCM External Pentest Playbook
- [ ] Hands-on (4 h): run the external workflow on a practice target: subdomains, exposed services, login portals, then password spraying methodology in a lab
- [ ] Write-up (1 h): external finding in TCM format (EPT-001)

### Sat Mar 13 · Day 30 · Gap analysis and redo

- [ ] Gap analysis (1.5 h): list every attack or tool you needed a hint or a video for since Feb 6; rank by how likely it is to appear in the exam (AD attacks first)
- [ ] Redo (4 h): redo the top gaps with no video and only your cheat sheet: AD lab attacks first, then Windows privesc
- [ ] Learn (1 h): rewatch only the course sections for anything you still fumbled
- [ ] Write-up (1 h): one redone attack in report format

### Sun Mar 14 · Day 31 · AD box: Cicada

- [ ] Hands-on (5 h): HTB Cicada, blind (retired, needs VIP)
- [ ] Learn (1.5 h): IppSec's video and the 0xdf writeup; add every new command to the cheat sheet
- [ ] Write-up (1 h): Cicada in report format

### Sat Mar 20 · Day 32 · AD boxes: Support and Return

- [ ] Hands-on (5 h): HTB Support, then Return, blind; use NetExec wherever it fits
- [ ] Learn (1.5 h): IppSec and 0xdf on both
- [ ] Write-up (1 h): Support in report format

### Sun Mar 21 · Day 33 · AD box: Administrator

- [ ] Hands-on (5 h): HTB Administrator, blind. EscapeTwo is an optional extra if you finish early
- [ ] Learn (1.5 h): IppSec and 0xdf; clean up the cheat sheet
- [ ] Write-up (1 h): Administrator in report format

### Sat Mar 27 · Day 34 · Mock engagement 1

Use the best multi-machine AD environment you have access to: a THM AD network you haven't seen, or an AD lab you built.

- [ ] External recon and initial access (2.5 h)
- [ ] Internal enumeration and lateral movement (3 h)
- [ ] Domain controller compromise and evidence collection (1 h)
- [ ] Running notes and screenshots, organised as you go (1 h)

### Sun Mar 28 · Day 35 · Mock 1 report

- [ ] Write the full report, External and Internal sections (5 h)
- [ ] Claude critiques it (1.5 h)
- [ ] List gaps to fix before Mock 2 (1 h)

---

# Phase 3: Rehearsal and taper (Apr 3 – Apr 11)

### Sat Apr 3 · Day 36 · Mock engagement 2

A different AD environment from Mock 1.

- [ ] External recon and initial access (2.5 h)
- [ ] Internal enumeration and lateral movement (3 h)
- [ ] Domain controller compromise and evidence collection (1 h)
- [ ] Running notes and screenshots (1 h)

### Sun Apr 4 · Day 37 · Mock 2 report and debrief

- [ ] Write the report (4 h)
- [ ] Build a short debrief deck: intro, contents, attack overview, attacks and impacts, remediation plan (1.5 h)
- [ ] Record yourself giving the 15-minute debrief and review it (1.5 h)
- [ ] Fix gaps (0.5 h)

### Sat Apr 10 · Day 38 · Taper

- [ ] Review the cheat sheet (1.5 h)
- [ ] Check tools, VPN and VMs (1.5 h)
- [ ] Early night

### Sun Apr 11 · Day 39 · Final logistics

- [ ] Voucher, scheduling, screen recording, food, rest
- [ ] No new material

---

# Exam week

### Mon Apr 12 · Exam day 1

- [ ] Read the Rules of Engagement
- [ ] Check whether to wait after the VPN or environment is ready before starting (a recent passer waited 15 minutes)
- [ ] External recon and OSINT
- [ ] Screenshot and note everything from minute one
- [ ] Stop at a set time and sleep

### Tue Apr 13 · Exam day 2

- [ ] Initial access
- [ ] Try each attack up to 3 times; reset the environment if something behaves oddly
- [ ] Stop at a set time and sleep

### Wed Apr 14 · Exam day 3

- [ ] Internal enumeration and AD attacks
- [ ] Note each success, then try the other attacks before going deep
- [ ] Stop at a set time and sleep

### Thu Apr 15 · Exam day 4

- [ ] Lateral movement toward the domain controller
- [ ] Keep evidence and notes current
- [ ] Stop at a set time and sleep

### Fri Apr 16 · Exam day 5

- [ ] Domain controller compromise
- [ ] Fill evidence gaps before the testing window closes
- [ ] Stop at a set time and sleep

### Sat Apr 17 · Report day 1

- [ ] Draft the report from your notes and screenshots; report the key findings, not every finding

### Sun Apr 18 · Report day 2

- [ ] Finish and proofread the report
- [ ] Submit it

### Apr 19–30 · Buffer

- [ ] Schedule and rehearse the live debrief
- [ ] Retake window if needed

---

# Milestones

- [ ] Phase 0 complete (Day 19, Jan 31)
- [ ] Voucher bought, exam date locked, leave requested
- [ ] Phase 1 complete, privesc gate passed (Day 27, Feb 28)
- [ ] Phase 2 complete, Mock 1 report done (Day 35, Mar 28)
- [ ] Mock 2 complete, debrief rehearsed (Day 37, Apr 4)
- [ ] Exam passed

---

# Appendix: Comparison with the original 16-week plan

This final plan merges the original 16-week plan with the dated, weekend-only plan built in this project.

## What was kept from the original

- **Redo labs with no videos, then a gap analysis.** Added as Day 30 and the repeat-until-clean rule.
- **Documentation system and tracker.** Added as its own section.
- **Exam-day principles.** Merged with the passer tips above.
- **One course per focus block.** Phase 1 and Phase 2 follow the TCM course order.

## Where each plan is stronger

| Area | Original | This plan | Better |
| --- | --- | --- | --- |
| Fit to your schedule | No dates; assumes 2–3 h every day, 7 days a week | Dated, weekend-only, clock times, Dec 26–27 blocked | This plan |
| TCM course coverage | All five courses, one per week | All five, after a free AD foundation | Tie |
| AD depth | PEH AD sections, then HTB boxes | THM AD module, PEH AD, 5 AD boxes, NetExec | This plan |
| Pivoting | sshuttle and proxychains | Wreath covers chisel, plink, socat, sshuttle and more | This plan |
| Repetition and gap analysis | Weeks 7–8 and 12 | One gap day plus redo rule | Original |
| Reporting | Dedicated week, built up in steps | Daily 1-hour write-up, two mock reports, debrief rehearsal | This plan |
| Mock exam | 5 days on Forest and Sauna | Two multi-machine mocks, 2 days each | This plan |
| Tracking and documentation | Dedicated system | Added from the original | Original |

## Errors found in the original

- UpDown is listed by HTB as a medium Linux machine, so it has no AD component.
- I could not confirm that BlackPearl and Butler are HTB machines; check before scheduling them.
- Forest and Sauna are separate machines, not one connected network, so they don't simulate the exam's external-to-internal chain.
- The claim that following the plan guarantees a pass is not something any plan can promise.
- I could not find the two GitHub repos it cites (jayshalwala/AD-PNPT-Study-Guide and peterrakolcza/PNPT-study-guide), nor verify its hour estimates; I left them out.
