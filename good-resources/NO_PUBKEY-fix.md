`Error: The repository 'http://http.kali.org/kali kali-rolling InRelease' is not signed'`
`Warning: GPG error: The following signatures couldn't be verified because the public key is not available: NO_PUBKEY ED65462EC8D5E4C5`

StackOverflow fix: [Link](https://superuser.com/questions/1644520/apt-get-update-issue-in-kali)

Steps:
1. First make sure you have a proper working apt source list by running `vim /etc/apt/sources.list` and checking if it matches the kali network repositories in the documentation
2. `wget -O kali-archive-keyring_2025.1_all.deb https://http.kali.org/kali/pool/main/k/kali-archive-keyring/kali-archive-keyring_2025.1_all.deb`, change the version as needed by going [here](https://pkg.kali.org/pkg/kali-archive-keyring)
3. `sudo dpkg -i kali-archive-keyring_2025.1_all.deb` to install
4. `sudo apt update && sudo apt full-upgrade`