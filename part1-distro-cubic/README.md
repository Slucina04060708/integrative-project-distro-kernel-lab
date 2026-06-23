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
