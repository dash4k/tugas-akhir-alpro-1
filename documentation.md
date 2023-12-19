# Final Project Algoritma dan Pemrograman

![C][C.badge]
[![CMake][CMake.org]][CMake-url]
[![Visual Studio Code][code.visualstudio.com]][VScode-url]
[![Github][Github.com]][Github-url]
</br></br>

This is the full documentation of the code that are used in <a href="https://github.com/dash4k/tugas-akhir-alpro-1">tugas-akhir-alpro-1</a></br>
For more information, please read the `README.md`
</br></br>

<details>
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#main">Main Function</a></li>
    <li>
      <a href="#primary">Primary Function</a>
      <ul>
        <li><a href="contact-h">contact.h</a></li>
        <li><a href="contact-c">contact.c</a></li>
      </ul>
    </li>
    <li>
      <a href="#utilities">Utilities Function</a>
      <ul>
        <li><a href="util-h">util.h</a></li>
        <li><a href="util-c">util.c</a></li>
      </ul>
    </li>
  </ol>
</details>

<a name="main"></a>
## Main
Inside the main function or `main.c`, we are only going to write code with the function that are previously defined inside `contact.h` and `util.h`.
So there will be no function declaration or function initialization be written here.
</br>

![code](https://github.com/dash4k/tugas-akhir-alpro-1/assets/133938416/eb153701-791c-428b-8aed-1b5e880d8f77)

These are the libraries that we are going to use inside the `main()` function. The first one is `<stdio.h>` for standard input and output function (e.g. `printf()` and `scanf()`).
And the second one is `contact.h` which is where our predefined function is located.
</br>

![code1](https://github.com/dash4k/tugas-akhir-alpro-1/assets/133938416/7499a0d9-c423-4406-917b-68f0afb6ee0a)

Inside the `main()` function, firstly we are going to print `printf("\033[44m");` and `printf("\033[1;36m");` that are going to change the terminal window's color to dark blue and the text inside it to be light blue. </br>
Then, we are going to declare several types of variables, each one for different uses:
* `FILE* file;` is a file pointer that we are going to use for referencing the file we want to edit.
* `bool quit = false;` is a boolean type variable used to store `flag` which is used to control the infinite `while()` loop for our menu driven app.
* `int choice = -1;` is an integer for storing the user's input of the menu they are choosing.
* `char ch;` is used to check and clear the input stream later on.












[C.badge]: https://img.shields.io/badge/C-A8B9CC.svg?style=for-the-badge&logo=C&logoColor=black
[CMake.org]: https://img.shields.io/badge/CMake-064F8C.svg?style=for-the-badge&logo=CMake&logoColor=white
[CMake-url]: https://cmake.org/
[code.visualstudio.com]: https://img.shields.io/badge/Visual%20Studio%20Code-007ACC.svg?style=for-the-badge&logo=Visual-Studio-Code&logoColor=white
[VScode-url]: https://code.visualstudio.com/
[Github.com]: https://img.shields.io/badge/GitHub-181717.svg?style=for-the-badge&logo=GitHub&logoColor=white
[Github-url]: https://github.com/
