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
