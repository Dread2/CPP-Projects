Windows System Repair Tool, a windows terminal utility to run SFC/DISM/CHKDSK sequentially with options Y/N.
Copyright (C) <2022>  <Gabe Finamore and Julian Tong>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>

#include <stdlib.h> // Important for control of processes, memory, conversion, etc
#include <iostream> // Standard input and outpout
#include <cstdlib> // System function
#include <windows.h> // Wait function

int main()
{
    //Defined Variables and values
    std::string value;
    std::string value1;
    std::string terms; // Terms and Conditions
    // Program start with details and bug report info
    system("color 0B");
    std::cout << "#################################################################" << std::endl;
    std::cout << "                 Windows Operating System Repair          V:1.43" << std::endl;
    std::cout << "#################################################################" << std::endl;
    std::cout << "\n";
    std::cout << "MAKE SURE TO RUN AS ADMINISTRATOR!" << std::endl;
    std::cout << "\n";
    std::cout << "This is an automated program for running SFC, DISM, and ChkDsk" << std::endl;
    std::cout << "tools with a single file. If you encounter any issues, email me" << std::endl;
    std::cout << "with the following format:" << std::endl;
    std::cout << "Email: julianeatong@gmail.com" << std::endl;
    std::cout << "Subject: Windows OS Repair Report" << std::endl;
    Sleep(5000);
    std::cout << "\n";
    std::cout << "\n";
    // Terms and Conditions
    std::cout << "\n";
    std::cout << "By continuing to use this program, you AGREE to the terms and conditions" << std::endl;
    std::cout << "\n";
    std::cout << "The program will continue after 20 seconds..." << std::endl;
    Sleep(20000);
    // SFC Parameters
    std::cout << "#################################################################" << std::endl;
    std::cout << "                      System File Checker                        " << std::endl;
    std::cout << "#################################################################" << std::endl;
    system("sfc.exe /scannow"); // Run SFC Scannow with system function from cstdlib
    std::cout << "\n";
    //DISM Parameters
    std::cout << "#################################################################" << std::endl;
    std::cout << "            Deployment Image Servicing and Management            " << std::endl;
    std::cout << "#################################################################" << std::endl;
    std::cout << "\n";
    std::cout << "Do you want to run Disk Image Servicing and Management tool? Y or N";
    std::cout << "\n";
    std::cin >> value;
    if (value == "Y" || value == "y") {
        std::cout << "\n";
        system("Dism /Online /Cleanup-Image /CheckHealth");
        std::cout << "\n";
        std::cout << "Please wait...";
        std::cout << "\n";
        Sleep(1000); // Sleep for 1s, 1000ms = 1
        system("Dism /Online /Cleanup-Image /RestoreHealth");
        std::cout << "\n";
        goto ChkDsk;
    }
    if (value == "N" || value == "n"); {
        goto ChkDsk;
    }
    //Check Disk Parameters

ChkDsk:
    std::cout << "#################################################################" << std::endl;
    std::cout << "                       Windows Check Disk                        " << std::endl;
    std::cout << "#################################################################" << std::endl;
    std::cout << "\n";
    std::cout << "Do you want to run CheckDisk? This requires a system restart... Y or N" << std::endl;
    std::cin >> value1;
    std::cout << "\n";
    if (value1 == "Y" || value1 == "y") {
        system("CHKDSK / F / R / X");
        std::cout << "\n";
        Sleep(5000);
        exit;
    }
    if (value1 == "N" || value1 == "n") {
        std::cout << "\n";
        std::cout << "Script Complete!";
        Sleep(5000);
        exit;
    };
}
