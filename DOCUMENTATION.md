# Final Project Algoritma dan Pemrograman

![C][C.badge]
[![CMake][CMake.org]][CMake-url]
[![Visual Studio Code][code.visualstudio.com]][VScode-url]
[![Github][Github.com]][Github-url]
</br></br>

This is the full documentation of the code that are used in <a href="https://github.com/dash4k/tugas-akhir-alpro-1">tugas-akhir-alpro-1</a></br>
For more information, please read the `README.md`
</br></br>

<a name="table-content"></a>
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#main">Main Function</a>
      <ul>
        <li><a href="#main-library">Library Declaration</a></li>
        <li><a href="#main-variable">Local Variable Declaration</a></li>
        <li><a href="#main-menu">Main Menu</a></li>
        <li><a href="#main-case-1">Add Contact</a></li>
        <li><a href="#main-case-2">Show Contact</a></li>
        <li><a href="#main-case-3">Modify Contact</a></li>
        <li><a href="#main-case-4">Search Contact</a></li>
        <li><a href="#main-case-5">Delete Contact</a></li>
        <li><a href="#main-case-6">Reset Contact</a></li>
        <li><a href="#main-case-7">Exit</a></li>
      </ul>
    </li>
    <li>
      <a href="#primary">Primary Function</a>
      <ul>
        <li>
          <a href="#contact-h">contact.h</a>
          <ul>
            <li><a href="#contact-h-libraries">Libraries Declaration</a></li>
            <li><a href="#contact-h-struct">Contact Struct</a></li>
            <li><a href="#contact-h-function">Function Declaration</a></li>
          </ul>
        </li>
        <li>
          <a href="#contact-c">contact.c</a>
          <ul>
            <li><a href="#contact-c-get-contact">get_contact()</a></li>
          </ul>
        </li>
      </ul>
    </li>
    <li>
      <a href="#utilities">Utilities Function</a>
      <ul>
        <li><a href="#util-h">util.h</a></li>
        <li><a href="#util-c">util.c</a></li>
      </ul>
    </li>
  </ol>
</details>

<a name="main"></a>
## Main
Inside the main function or `main.c`, we are only going to write code with the function that are previously defined inside `contact.h` and `util.h`.
So there will be no function declaration or function initialization be written here.
</br>
<p align="right">(<a href="#table-content">back to table of content</a>)</p>
</br>

<a name="main-library"></a>
### Library Declaration
![code](https://github.com/dash4k/tugas-akhir-alpro-1/assets/133938416/eb153701-791c-428b-8aed-1b5e880d8f77)

These are the libraries that we are going to use inside the `main()` function. The first one is `<stdio.h>` for standard input and output function (e.g. `printf()` and `scanf()`).
And the second one is `contact.h` which is where our predefined function is located.
</br>
<p align="right">(<a href="#table-content">back to table of content</a>)</p>
</br>

### Local Variable Declaration
<a name="main-variable"></a>
![code1](https://github.com/dash4k/tugas-akhir-alpro-1/assets/133938416/7499a0d9-c423-4406-917b-68f0afb6ee0a)

Inside the `main()` function, firstly we are going to print `printf("\033[44m");` and `printf("\033[1;36m");` that are going to change the terminal window's color to dark blue and the text inside it to be light blue. </br>
Then, we are going to declare several types of variables, each one for different uses:
* `FILE* file;` is a file pointer that we are going to use for referencing the file we want to edit.
* `bool quit = false;` is a boolean type variable used to store `flag` which is used to control the infinite `while()` loop for our menu driven interface.
* `int choice = -1;` is an integer for storing the user's input of the menu they are choosing.
* `char ch;` is used to check and clear the input stream later on.
</br>
<p align="right">(<a href="#table-content">back to table of content</a>)</p>
</br>

<a name="main-menu"></a>
### Main Menu
![code2](https://github.com/dash4k/tugas-akhir-alpro-1/assets/133938416/a020b55b-3317-4068-bce4-89955548263c)

Next, we are going to declare the `while()` loop for our menu driven interface with `!quit` as its parameter. Inside this loop, the first thing we are going to do is clearing the terminal windows screen using `clear_screen()` function. After that we are going to print the main menu for our program with bunch of `printf()` and we're also going to ask for user's choice of which features they like to use with `scanf("%d", &choice);`.
</br>
<p align="right">(<a href="#table-content">back to table of content</a>)</p>
</br>

<a name="main-case-1"></a>
### Add Contact
![code3](https://github.com/dash4k/tugas-akhir-alpro-1/assets/133938416/15bd8c74-91a8-44d6-8872-0a190aaf13d2)

Then, we are going to use `switch` statement for our menu driven interface with `choice` as its parameter. The first condition is going to be `Add Contact` which is where we are going to create our adding contact feature. </br></br>
After we clear our screen, then we are going to print the header of the program. After that we declare a structure called `Contact` and we named it `addContact`. Then we ask the user for the name of the contact, and before we store it inside the `addContact.name` with the `fgets()` function, we first need to clear the input stream with `while ((ch = getchar()) != '\n' && ch != EOF);`. And after that we stored the user's input and then call `rmv_newline()` function with `addContact.name` as its parameter to remove any `\n` that are found inside the `addContact.name`. Next, we are going to ask the user for the contact phone number and the contact email.</br></br>
After that, we clear the screen one more time and show the user the contact name, phone number, and email that will be saved to the contact app. We then use `system("pause");` to temporarily stop the program until the user press any button on their keyboard. And lastly, we are going to call `add_contact()` function with `addContact` variable and `file` as its parameters.
</br>
<p align="right">(<a href="#table-content">back to table of content</a>)</p>
</br>

<a name="main-case-2"></a>
### Show Contact
![code5](https://github.com/dash4k/tugas-akhir-alpro-1/assets/133938416/14785c22-f45e-4510-93dc-424febd48749)

The second condition is going to be `Show Contact`, in which we are going to mmake our showing contact feature. This feature is pretty simple, we first clear the screen and then print the contact header. Then we are going to print the table header of the contact we want to show. Then we are going to call the `get_contact()` function with `file` as its parameter. Lastly we are going to stop the program temporarily with `system("pause")`. 
</br>
<p align="right">(<a href="#table-content">back to table of content</a>)</p>
</br>

<a name="main-case-3"></a>
### Modify Contact
![code6](https://github.com/dash4k/tugas-akhir-alpro-1/assets/133938416/ee6d696f-bb50-45ce-a20c-f0388da9dd5e)

The third condition is going to be `Modify Contact`. This is the feature where the user is able to modify the existing contact. Like every feature before this, we first are going to clear the screen and print the contact header. Then we are going to print a header table and `get_contact()` function with `file` as its parameter to show the existing contact. Next, we are going to declare two variables, the first one is an integer type variable called `contactIndex` to store the user's input for which contact they want to modify, the second one is a Contact type variable called modifyContact to store the changes that user's make to the existing contact.</br></br> 
Then, we are going to make the user input the new name / phone number / email for the existing contact and we store it in the `modifyContact`. Then we are going to call `modify_contact()` function and `contactIndex`, `modifyContact`, and `file` as its parameter to modify the existing contact with the new contact that user's inputted. Then we are going to show the new list with the contact already modified.
</br>
<p align="right">(<a href="#table-content">back to table of content</a>)</p>
</br>

<a name="main-case-4"></a>
### Search Contact
![code7](https://github.com/dash4k/tugas-akhir-alpro-1/assets/133938416/acd8d344-889d-4643-a555-12ae8fc7cd46)


The fourth condition is `Search Contact`. First we are going to clear the screen and print the contact header. Then we are going to declare a string variable called `searchContact` to store the user's input. Then we do the first step one more time, and then we are going to call `search_contact()` function with `searchContact` and `file` as its parameters and we store the return value of that function which is an array of interger, so we are going to store it in an integer pointer type variable called `searched_position`.</br></br>
After that, we are going to print what the user searched, and print how many contact matched what the user's searched. And when the value of `searched_position[0]` is more than 0 (i.e. we found something that match what the user's searched), we are going to print in which index we found the matching contact. Then we are going to call the `display_search()` function and `searched_position` and `file` as its parameter to display the matching contact we found with `search_contact()`. Then we are going to temporarily stop the program so the user can see which contact they're looking for. Lastly we are going to `free()` `searched_position` so that we dont have any memory leaks.
</br>
<p align="right">(<a href="#table-content">back to table of content</a>)</p>
</br>

<a name="main-case-5"></a>
### Remove Contact
![code8](https://github.com/dash4k/tugas-akhir-alpro-1/assets/133938416/ef549a4c-020e-4920-97a1-3fda26075e3d)

The fifth condition is going to be `Delete Contact`. Firstly, we are going to clear the screen and print the contact header. Then we are going to print a header table and `get_contact()` function with `file` as its parameter to show the existing contact. Then we are going to declare an integer type variable called `contactDelete` for storing the index of the contact the user want to delete.</br></br>
Then we ask the user to input which index they want to delete, and then we store the user's input to `contactDelete`. Then we are going to call `delete_contact()` function and `contactDelete` and `file` as its parameter. Then we are going to clear the screen and print the contact header one more time and print the newly modified contact with the contact which the user intended to delete is already been deleted.
</br>
<p align="right">(<a href="#table-content">back to table of content</a>)</p>
</br>

<a name="main-case-6"></a>
### Reset Contact
![code9](https://github.com/dash4k/tugas-akhir-alpro-1/assets/133938416/272b7f5b-6dd1-4f4d-8428-fdc4f874c01a)

The sixth condition and the last feature is `Reset Contact`. This feature is pretty self explanatory. It will reset the contact manager and removes everything from the contact file. After we clear the screen and print the contact header, we are going to declare a character type variable called `seriously` in which we are going to store the user's decision.</br></br> 
Then we are going to confirm the user's decision and store it inside the `seriously` variable. Then we are going to convert the character inside `seriously` to be lower cased with the `tolower()` function. After that we are going to make an if statement for the decision that user made. If the character inside the `seriously` variable is equal to lowered case `y`, we are going to call the `reset_contact` function which will reset the contact app. And if not, than we are going to stop the program temporarily with `system("pause")` function.
</br>
<p align="right">(<a href="#table-content">back to table of content</a>)</p>
</br>

<a name="main-case-7"></a>
### Exit
![code10](https://github.com/dash4k/tugas-akhir-alpro-1/assets/133938416/8420c0b8-443f-46d6-880c-66212849b4f0)

The last condition is going to be `Exit`. After clearing the screen and printing the contact header, we are going to declare a character type variable called `isSure` in which we are going to store the user's decision to exit the program or not. After that we are going to ask the user whether they want to quit or not, and if yes (i.e. `isSure` is equal to lowered case `y`) we are going to set `quit` value to be true and exit the program. And if not, we are going to temporarily stop the program with `system("pause")`.</br></br>
After breaking from the infinite loop and exiting the program, we will print `printf("\033[0m");` to change the color of the terminal and the text inside it to the default color and returning `0` to the terminal that will indicate the program is successfully run and closed.
</br>
<p align="right">(<a href="#table-content">back to table of content</a>)</p>
</br>
</br>


<a name="primary"></a>
## Primary Function
These are the primary function that we are going to use inside the main function, there are two files that we are going to use to create our primary function, the first one is `contact.h` for the function declaration, and the second one is `contact.c` for the function initialization. 
</br>
<p align="right">(<a href="#table-content">back to table of content</a>)</p>
</br>

<a name="contact-h"></a>
### Contact.h
This is where we declare the function that we are going to write in `contact.c`, and we can use the function that we created by including `contact.h` inside the `main.c` file.
</br>
<p align="right">(<a href="#table-content">back to table of content</a>)</p>
</br>

<a name="contact-h-libraries"></a>
#### Libraries Declaration
![code1](https://github.com/dash4k/tugas-akhir-alpro-1/assets/133938416/480d490d-242f-4008-96ef-12beaac73bec)

These are the libraries that we are going to use to help us create our function for contact manager. Notice that the first line of code is not like the others. This is because `#pragma` is not a type of library, but rather what we called a preprocessor, which is a command that we can tell the compiler to do something before compiling the rest of the code, and `#pragma once` is used to tell the compiler to only include the current source file once, meaning that everytime we compile the program, the compiler will not read the same header files again.
</br>
<p align="right">(<a href="#table-content">back to table of content</a>)</p>
</br>

<a name="contact-h-struct"></a>
#### Contact Struct
![code2](https://github.com/dash4k/tugas-akhir-alpro-1/assets/133938416/9459bf3e-5029-40ab-a1db-cc6bcbd5a35d)

In this file, we also going to declare a struct called `Contact`, which is where we are going to temporarily store the value of user's inputted contact name, phone number, and email, before we store it later on in a different file. We use `string` type of variable inside this struct to store the value of the contact.
</br>
<p align="right">(<a href="#table-content">back to table of content</a>)</p>
</br>

<a name="contact-h-function"></a>
#### Function Declaration
![code3](https://github.com/dash4k/tugas-akhir-alpro-1/assets/133938416/df1bb396-b08a-4f34-8949-ae104017b628)

We also going to declare our primary function here, so we don't have to declare it again later on `function.c`. The function that we are going to declare are the following:</br>
* `get_contacts()`: Is a function used to show the contacts inside a file. Which is going to take a `file` pointer as its parameter and will return an `integer` type of value.
* `add_contact()`: Is a function that help us store contact that user's inputted to a seperate contact file. Which is going to take a `Contact` type of variable (the struct that we declare before) and a `file` pointer as its parameter and will not return any type of value.
* `modify_contact()`: Is a function used to modify the value of an existing contact inside a contact file. Which is going to take an `integer` which we are going to use to locate an index of a contact, a `Contact` type of variable, and a `file` pointer as its parameter, and will return an `integer` type of value.
* `delete_contacts()`: Is a function that's going to remove a single contact inside a contact file. Which is going to take an `integer` which we are going to use to locate an index of a contact and a `file` pointer as its parameter, and will return an `integer` type of value.
* `search_contact()`: Is a function that we are going to use to iterate over our contact file to find a matching value of the user's searched value and the value inside our contact file. Which is going to take a `string` to be the search term of the function and a `file` pointer as its parameter, and will return an `array` of `integer` as its return value.
* `display_search()`: Is a function that we are going to use to display the matching value that we found with the `search_contact()` function. Which is going to take the return value of `search_contact` which is an `array` of `integer` to be the index of the contact that we are going to display and a `file` pointer as its parameter, and will return an `integer` type of of value.
* `reset_contact()`: Is a function used to reset or remove every value inside our created contact file. Which is going to take a `file` pointer as its parameter and will return an `integer` type of value.
</br>
<p align="right">(<a href="#table-content">back to table of content</a>)</p>
</br>

<a name="contact-c"></a>
### Contact.c
This is where we define our predeclared function in `function.h`. The first line of this file will be `#include "contact.h"` which is the syntax we use to reference the `contact.h` header file.  
</br>
<p align="right">(<a href="#table-content">back to table of content</a>)</p>
</br>

<a name="contact-c-get-contact"></a>
#### get_contacts()
![code1](https://github.com/dash4k/tugas-akhir-alpro-1/assets/133938416/b12062a4-bd8b-4811-83da-4e4d7121e78f)

In the get_contact() function, the procedure is pretty simple, first we create the `Contact` type variable for printing the `Contact` value inside the contact file, and then we declare an integer named `total_contacts` and initialize it with `1` to display the first index and later the second until the last index after we modify the value of it inside a `while()` loop later on. </br></br>
After that we are going to use the `file` pointer from the function parameter to call `fopen()` function to link our function with our seperate contact file and use the `fopen()` function in `rb` or read binary mode so that later we can print the value of our seperate contact file in the user's terminal window. Then we check whether the `file` pointer is equals to `NULL` which mean that the pointer is pointing to no where inside the memory and when that happened we terminate the process immediately by printing a message telling the user that nothing can be found inside the file and then we call the `fclose()` function to close the current file and returning code 1 to the terminal window to inform the user that the program was having an error. </br></br>
After we successfully locate the `file` pointer location and found data inside it, we then use a `while()` loop with `fread()` as its condition and pass the `Contact` struct that we created as the first parameter to the `fread()` function to be the buffer where the data is stored, `sizeof(contact)` as the second parameter to be the limit of our iteration, `1` as the third parameter to be the number of elements to be read, and lastly `file` as the fourth parameter to be the pointer of the file we linked before. </br></br>
Inside the `while()` loop we are going to print the value inside the contact file with a specified template to print it like a table. After that we increment the `total_contacts` value to follow how many time we iterate over the file. </br></br>
After we done with the `while()` loop, we then close the file we open before with `fclose(file)` and return 0 to the terminal to indicate we successfully called the `get_contact()` function. 
</br>
<p align="right">(<a href="#table-content">back to table of content</a>)</p>
</br>


















[C.badge]: https://img.shields.io/badge/C-A8B9CC.svg?style=for-the-badge&logo=C&logoColor=black
[CMake.org]: https://img.shields.io/badge/CMake-064F8C.svg?style=for-the-badge&logo=CMake&logoColor=white
[CMake-url]: https://cmake.org/
[code.visualstudio.com]: https://img.shields.io/badge/Visual%20Studio%20Code-007ACC.svg?style=for-the-badge&logo=Visual-Studio-Code&logoColor=white
[VScode-url]: https://code.visualstudio.com/
[Github.com]: https://img.shields.io/badge/GitHub-181717.svg?style=for-the-badge&logo=GitHub&logoColor=white
[Github-url]: https://github.com/
