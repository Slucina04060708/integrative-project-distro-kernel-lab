# Integrative Project: Build, Boot, and Attack

This repository contains the full-stack development of our Integrative Project, spanning from custom distribution generation, OS kernel architecture from scratch, to containerized security lab orchestration and offensive testing.

---

## Group Members & Roles

* **Pamela Stefania Toapanta Pila** — Part 1: Custom Distro Generation (Cubic)
* **Camila Isabel Paucar Guaranda** — Part 2: 64-bit Kernel Architecture (Multiboot2/C)
* **Santiago Alejandro Lucina Mena** — Part 3: Black Hat Bash Lab & Defensive Auditing

---

## How to Reproduce All 3 Parts

Below are the condensed execution frameworks to verify, each component of the project. Detailed structural breakdowns can be found inside the respective subfolder `README.md` files.

---

### Part 1 — Build Your Distro with Cubic

#### Technical Specifications of the Test Environment (VM)

To ensure the correct execution and validation of *CapsaISO*, the virtualized environment must be configured with the following technical parameters:

* *Base Used*:
    * *Base distribution*: Ubuntu (64-bit)
    * *Image name*: CapsaISO-1.0-desktop-amd64.iso
    * *Integrity verification*: CapsaISO-1.0-desktop-amd64.md5

* *Virtual Machine Setup*:
    * *Name*: CapsaISO-Test
    * *OS Type*: Linux / Ubuntu (64-bit)

* *System settings*:
    * *Base Memory*: 4096 MB (Recommended for smooth graphical environment performance)
    * *Processors*: 2 CPUs
    * *Boot Order*: EFI, Optical, Hard Disk
    * *Acceleration*: KVM Paravirtualization

* *Display settings*:
    * *Video Memory*: 128 MB
    * *Graphics Controller*: VMSVGA (with 3D acceleration enabled)

* *Storage settings*:
    * *Controller*: IDE / SATA
    * *Optical Drive*: CapsaISO-1.0-desktop-amd64.iso (Live CD/DVD mode enabled)

* *Network settings*:
    * *Adapter 1*: NAT (Provides internet access through the host)

---

*Note to the professor:* This configuration ensures that the boot process from the mounted CapsaISO-1.0-desktop-amd64.iso image and the verification of customizations (themes, wallpapers, and GSchema configurations) are performed efficiently, optimizing the experience within the system's "Live" session.

### Part 2 — Development Environment Setup & Execution Guide

This document provides the precise configuration steps and toolchain requirements to reproduce, compile, and emulate the custom 64-bit operating system kernel from scratch.

---

#### 1. System Prerequisites

Before initializing the build pipeline, ensure the following virtualization and containerization engines are installed and active on the host machine:
* **Docker Desktop**: Required to orchestrate the isolated cross-compilation environment toolchain.
* **QEMU Emulator**: Required for the bare-metal architecture hardware simulation stage.

---

#### 2. Dockerfile Infrastructure Configuration

The environment definition file (Dockerfile) must be explicitly configured and placed inside the designated build management folder:

Path Target: part2-kernel/buildenv/Dockerfile

*(Note: This container image pre-packages the freestanding x86_64-elf-gcc cross-compiler, NASM assembler, and GNU GRUB utilities to prevent toolchain drift).*

---

#### 3. Execution Steps (Toolchain Compilation & Emulation)

##### Step 1: Toolchain Image Compilation
Launch your system terminal interface and execute the following command to assemble the reproducible compiler container image:

docker build -t myos-buildenv .

##### Step 2: Container Environment Workspace Mount
Run the compiled Docker build engine to mount your current repository root workspace directory. This cross-compiles the assembly headers, links the C files, and generates the bootable image file structures:

docker run --rm -it -v ${PWD}:/root/env myos-buildenv

##### Step 3: Container Disconnection Sequence
Once the compiler script successfully terminates and outputs the definitive kernel binary assets inside the distribution layer, drop out of the containerized environment context back to your host terminal system:

exit

##### Step 4: Virtualized Hardware Emulation via QEMU
Execute the system hypervisor emulator tool by explicitly mapping the exact operational path of the local executable engine. This reads the distribution manifest structure and boots the compiled system kernel profile:

& "C:\Program Files\qemu\qemu-system-x86_64.exe" -cdrom dist/x86_64/kernel.iso

---

> **Windows / PowerShell Execution Note:** The execution command uses the call operator (&) and literal quotation marks to safely parse the default installation path under Microsoft Windows architectures. Ensure the target file 'dist/x86_64/kernel.iso' exists before calling the hypervisor hook.

### Part 3 — Stand Up and Attack the Black Hat Bash Lab
A containerized, multi-network offensive security lab architecture. This entire environment was deployed, tested, and audited within an isolated **Debian 13 (Trixie)** Virtual Machine. The project directory contains the complete verification logs, step-by-step documentation, and evidence metrics.

#### Prerequisites
* Isolated Virtual Machine running **Debian 13 (Trixie)** or Kali Linux.
* Hardware Resource Allocation: Minimum **4 GB RAM** and **40 GB Disk Space** configured for the guest OS.
* **Docker** and **Docker Compose** toolchains installed and active inside the virtual machine.

#### Execution Steps (Inside the Debian VM)

##### Phase 1: Environment Setup & Docker Installation

**1.** Update the local system repositories:

    sudo apt update

**2.** Install critical secure connection dependencies and encryption tools:

    sudo apt install -y ca-certificates curl gnupg

**3.** Initialize the protected directory system layout for administrative repository keys:

    sudo install -m 0755 -d /etc/apt/keyrings

**4.** Download and import the official Docker GPG security verification key:

    curl -fsSL https://download.docker.com/linux/debian/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg

**5.** Set read permissions on the secure key file:

    sudo chmod a+r /etc/apt/keyrings/docker.gpg

**6.** Dynamically detect the operating system distribution code name and register the stable production Docker repository source list channel:

    echo "deb [arch="$(dpkg --print-architecture)" signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/debian "$(. /etc/os-release && echo "$VERSION_CODENAME")" stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null

**7.** Re-synchronize system indexes to incorporate the newly integrated package listings:

    sudo apt update

**8.** Install the latest production stable builds for the Docker engine service, command-line interfaces, containerd runtimes, and the modern orchestration toolchain extensions:

    sudo apt install -y docker-ce docker-ce-cli containerd.io docker-buildx-plugin    |docker-compose-plugin

**9.** Install the traditional GNU compilation script parser utility required for runtime execution automation scripts:

    sudo apt install -y make

---

##### Phase 2: Lab Deployment & Orchestration

**10.** Clone the targeted official project framework codebase locally from GitHub:

    git clone https://github.com/dolevf/Black-Hat-Bash.git

**11.** Move into the designated network configuration and microservices orchestration directory:

    cd Black-Hat-Bash/lab

**12.** Run the automated provisioning manifest workflow tool to assemble, bind networks, download external containers, and start infrastructure resources:

    sudo make deploy

**13.** Monitor installation event outputs, execution variables, and live compilation system output channels in real-time if necessary:

    sudo tail -f /var/log/lab-install.log

---

##### Phase 3: Verification & Network Auditing

**14.** Execute the automated network validation profile to audit port states and confirm health metrics match deployment properties (*Lab is up*):

    sudo make test

**15.** Query active system container endpoints to audit specific cluster node mappings and configuration profiles:

    sudo docker ps --format "{{.Names}}"

**16.** Scan and isolate running system link bindings to verify correct bridge subnets are active for the infrastructure segments:

    ip addr | grep "br_"

**17.** Establish an interactive remote terminal administrative session directly inside the isolated exterior web node environment container to audit active system assets:

    sudo docker exec -it p-web-01 bash

**18.** Change workspace directory back to the repository base to handle maintenance tasks:

    cd Black-Hat-Bash

---

##### Phase 4: Target Reconnaissance & Hacking Technique Execution

**19.** Analyze the PORTS column from the global container infrastructure mapping to pinpoint active, public-facing HTTP entry vectors (discovering port 80 open on p-web-02):

    sudo docker ps

**20.** Run the automated Directory/Path Enumeration attack technique against the discovered responsive HTTP port on the dual-homed target interface:

    dirsearch -u http://172.16.10.12:80