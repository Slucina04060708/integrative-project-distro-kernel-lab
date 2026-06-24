---------------------PART 1 - BUILD YOUR DISTRO WITH CUBIC---------------------

-----------------------------------------
1.-Install Cubic on the Ubuntu/Mint host
-----------------------------------------
To establish the foundation for our custom distribution, we performed the installation of Cubic (Custom Ubuntu ISO Creator)
on our host machine. This tool is essential for the project as it provides a controlled chroot environment, enabling
the extraction, modification, and reconstruction of an Ubuntu-based ISO image.

The installation process was executed by adding the project's official PPA to our repository list to ensure the
availability of the latest stable version and its dependencies. This step is critical to ensure that the environment
remains consistent throughout the modification lifecycle.
Execution Log:
## Add the PPA and update the package list
sudo apt-add-repository ppa:cubic-wizard/release
sudo apt update
## Install the application
sudo apt install cubic -y

/home/pame/Descargas/WhatsApp Image 2026-06-22 at 6.45.48 PM.jpeg 

--------------------------------------------------------
2.- Base ISO selection and project naming
--------------------------------------------------------
The selection of the base image is a critical decision in the distribution construction process, as it determines the repository ecosystem,
the default kernel version, and the overall stability of the final environment. For this project, we chose: Ubuntu 24.04 LTS as the foundation.

This specific release was selected due to its long-term support (LTS) status, which ensures consistent security patching and a stable core that
is essential for the security and networking experiments planned in the subsequent phases of this integrative project.

After verifying the integrity of the ISO, we initialized the project with the identifier CapsaOS. This naming convention is not merely nominal;
it defines the root environment within the Cubic workspace, where all subsequent system modifications, dependency installations, and configuration
changes will be applied before the final squashfs compression.
/home/pame/Imágenes/Capturas de pantalla/Captura desde 2026-06-22 23-05-47.png 

---------------------------------------------------------------
3.- IMPLEMENTATION OF CHANGES TO THE ISO STANDART
---------------------------------------------------------------
## *3.1)Software replacement: Transmission to qbitorrent*

In our pursuit of creating a specialized distribution focused on security and network efficiency, we evaluated the default P2P client, Transmission.
While Transmission is lightweight, it lacks the advanced queue management and detailed network bandwidth control required for rigorous research environments.
We decided to perform a replacement with qBittorrent.

# Technical Justification
-Feature Completeness: qBittorrent offers a more robust feature set, including an integrated search engine, advanced sequential downloading, and
 detailed torrent prioritization, which are essential for managing large research datasets efficiently.
-Stability and Performance: By utilizing the qBittorrent provides superior performance under high-load scenarios
 compared to the default client.

# Implementation Procedure
The modification was executed within the chroot environment of the Cubic workspace:
-Repository Update: Synchronized local package indices to ensure the latest stable version of qBittorrent was retrieved.
-Deployment: Executed the installation via the standard apt package manager to ensure dependency integrity.
-Removal: Purged the transmission-gtk and transmission-common packages to reduce the attack surface and remove redundant binaries.
-Verification: Validated the installation via binary path identification.

/home/pame/Descargas/WhatsApp Image 2026-06-23 at 7.37.50 PM.jpeg 

## *3.2 Software Replacement: Celluloid to mpv*
To streamline our multimedia handling and minimize graphical dependencies in the background, we replaced the default Celluloid player with mpv.
This transition is consistent with our design philosophy of prioritizing command-line efficiency and resource optimization.

# Technical Justification
-Minimalist Architecture: mpv is renowned for its low overhead and lack of unnecessary GUI bloat, providing a direct and efficient rendering path
 for multimedia files.
-Extensibility: Its design as a modular player allows for deeper integration with scripts and external automation tools, which is highly beneficial
 for a system-focused distribution like CapsaOS.
-Efficiency: By stripping away the GTK-based frontend of Celluloid, we reduce the total package footprint and the complexity of the media-handling
 stack.

# Implementation Procedure
-Deployment: Installed mpv through the official distribution repositories to maintain system stability.
-Removal: Purged celluloid to prevent package conflicts and ensure that only the leanest tools remain in the distribution image.
-Verification: Validated the installation by checking the binary location.

/home/pame/Descargas/WhatsApp Image 2026-06-23 at 8.02.58 PM.jpeg 

## *3.3 Custom Environment Configuration: /etc/skel*
To ensure a standardized and productive user experience, we configured the /etc/skel directory. This directory serves as the template for every new user account created on the system, guaranteeing that personal settings and directory structures are applied immediately upon account creation.

# Technical Justification
-User Provisioning: By pre-defining the directory structure (Desktop, Documents, Projects), we reduce the manual setup time for new users.
-Standardization: The inclusion of an alias in .bashrc for package management (update) ensures that all users adopt best practices for system maintenance.
-System Identity: The BIENVENIDA.txt file on the desktop provides an immediate identifier for the distribution’s customized nature.

# Implementation Procedure
-Structure Definition: Created standard workspace directories within /etc/skel.
-Configuration Injection: Appended custom shell aliases to the skeletal .bashrc file to enhance terminal productivity.
-Identity Branding: Placed a custom welcome document in the skeletal Desktop directory to acknowledge the system customization.

/home/pame/Descargas/WhatsApp Image 2026-06-23 at 8.39.39 PM.jpeg 

## *3.4 Default Desktop Environment Customization*
To ensure a cohesive and branded user experience, we enforced a custom system-wide desktop theme via GSchema overrides. Instead of requiring users to manually change settings, we configured the environment to default to a 'Dark' color scheme and a standardized theme.

# Technical Justification
-System-wide Enforcement: By creating a .gschema.override file, we ensure that the desktop environment settings are hardcoded as the default for
 all new users, overriding standard system defaults.
-Non-Interactive Configuration: Using glib-compile-schemas during the build process ensures that the settings are pre-compiled and immediately
 active upon the first login, providing a "ready-to-use" professional feel.

# Implementation Procedure
-Schema Override Creation: Developed an override file (01_capsaiso_defaults.gschema.override) defining preferred visual properties, including
 the Yaru-dark theme and the system-wide 'Dark' color scheme.
-Branding Integration: Integrated a custom wallpaper (capsa_fondo.jpg) as the default background, ensuring consistent group identity across all
 user profiles.
-Compilation: Compiled the schema definitions using glib-compile-schemas to register the custom visual defaults within the GNOME settings system.

/home/pame/Descargas/WhatsApp Image 2026-06-23 at 9.43.55 PM.jpeg 

----------------------------------------------------------------------
4.-System Packaging and Compression
-----------------------------------------------------------------------
To optimize the distribution and portability of CapsaISO, we carefully selected the compression methodology used during the ISO generation process.

## Technical Choice: XZ Compression
-Methodology: We utilized XZ (LZMA2) as the primary compression algorithm.
-Justification: While alternative methods like gzip or lz4 offer faster compression times, xz was selected to achieve the highest possible
 compression ratio.
-Result: This choice minimizes the total disk image size, ensuring that the resulting ISO is efficient for storage and distribution, meeting the
 project's requirement for optimized file size.

/home/pame/Descargas/WhatsApp Image 2026-06-23 at 10.29.09 PM.jpeg 
