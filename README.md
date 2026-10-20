<p align="center">
  <img src="assets/banner.svg" alt="C++ Learning Resources" width="100%">
</p>

<p align="center">
  <a href="README.md"><img src="https://img.shields.io/badge/English-active-4aa3ff?style=for-the-badge" alt="English"></a>
  <a href="README.sr.md"><img src="https://img.shields.io/badge/Srpski-prebaci-7f8cff?style=for-the-badge" alt="Srpski"></a>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-17%20%7C%2020-00599C?style=flat-square&logo=cplusplus&logoColor=white" alt="C++17/20">
  <img src="https://img.shields.io/badge/CMake-supported-064F8C?style=flat-square&logo=cmake&logoColor=white" alt="CMake">
  <img src="https://img.shields.io/github/license/MIhajloS07/cpp-learning-resources?style=flat-square&color=7f8cff" alt="License">
  <img src="https://img.shields.io/github/stars/MIhajloS07/cpp-learning-resources?style=flat-square&color=4aa3ff" alt="Stars">
  <img src="https://img.shields.io/github/last-commit/MIhajloS07/cpp-learning-resources?style=flat-square&color=a47bff" alt="Last commit">
  <img src="https://img.shields.io/badge/PRs-welcome-28c840?style=flat-square" alt="PRs welcome">
</p>

<p align="center">
  <b>A structured, hands-on path through C++</b> — from your first <code>Hello, World!</code> to object-oriented design, the STL and modern C++.<br>
  Every topic comes with a small, readable example you can compile, run and modify.
</p>

<p align="center"><img src="assets/divider.svg" alt="" width="100%"></p>

## Table of contents

- [About](#about)
- [Who is this for](#who-is-this-for)
- [Learning path](#learning-path)
- [Getting started](#getting-started)
- [How to study with this repo](#how-to-study-with-this-repo)
- [Skills demonstrated](#skills-demonstrated)
- [Repository conventions](#repository-conventions)
- [Contributing](#contributing)
- [Related repositories](#related-repositories)
- [License](#license)
- [Author](#author)

## About

**C++ Learning Resources** is a learning-by-doing collection of C++ examples and exercises, organised so that each concept builds on the previous one. The focus is on:

- **Clarity** — short programs that demonstrate one idea at a time.
- **Practice** — exercises and mini-projects, not only theory.
- **Modern style** — idiomatic C++17/20: RAII, smart pointers, the STL and `const`-correctness instead of manual memory juggling.

## Who is this for

| Audience | What you get |
| --- | --- |
| 🎓 **Students & beginners** | A gentle, ordered path with runnable examples for every concept. |
| 🔁 **Developers switching to C++** | Quick refreshers on pointers, memory, templates and the STL. |
| 💼 **Recruiters & hiring managers** | A transparent record of how I learn, structure code and document it — see [Skills demonstrated](#skills-demonstrated). |

## Learning path

The material follows a progressive roadmap. Each stage builds on the previous one.

| Stage | Focus | Key topics |
| :---: | --- | --- |
| **1** | Fundamentals | Program structure, compilation, variables, types, operators, I/O (`iostream`) |
| **2** | Control flow & functions | `if`/`switch`, loops, functions, overloading, default arguments, recursion |
| **3** | Arrays, strings & pointers | C-arrays, `std::array`, `std::string`, pointers, references, `const` |
| **4** | Object-oriented programming | Classes, constructors/destructors, encapsulation, inheritance, polymorphism, operator overloading |
| **5** | Templates & the STL | Function/class templates, `vector`, `map`, `set`, iterators, `<algorithm>`, lambdas |
| **6** | Memory management | Stack vs heap, RAII, `unique_ptr`, `shared_ptr`, rule of 3/5/0 |
| **7** | Error handling & files | Exceptions, `fstream`, text/binary I/O, `std::filesystem` |
| **8** | Data structures & algorithms | Linked lists, stacks, queues, trees, sorting & searching, complexity |
| **9** | Modern C++ & projects | Move semantics, `auto`, ranges, `std::optional`, CMake, complete mini-projects |

> 💡 Start at the stage that matches your level — each folder is self-contained.

## Getting started

### Prerequisites

- A C++17-capable compiler: **GCC 9+**, **Clang 10+** or **MSVC 2019+**
- *(Optional)* **CMake 3.16+**
- *(Optional)* An editor such as **VS Code**, **CLion** or **Visual Studio**

### Clone

```bash
git clone https://github.com/MIhajloS07/cpp-learning-resources.git
cd cpp-learning-resources
```

### Build & run a single example

```bash
# GCC / Clang
g++ -std=c++20 -Wall -Wextra -pedantic main.cpp -o app
./app
```

```bat
:: MSVC (Developer Command Prompt)
cl /std:c++20 /EHsc /W4 main.cpp
main.exe
```

### Build with CMake

```bash
cmake -S . -B build
cmake --build build
```

## How to study with this repo

1. **Read** the example and predict its output before running it.
2. **Compile & run** it with warnings enabled (`-Wall -Wextra`).
3. **Modify** it — break it on purpose, then fix it.
4. **Re-write** the example from memory without looking.
5. **Solve** the exercise at the end of the topic, then move on.

## Skills demonstrated

- Core language: types, control flow, functions, references and pointers
- Object-oriented design: encapsulation, inheritance, polymorphism
- Generic programming: templates and the Standard Template Library
- Resource management: RAII, smart pointers, move semantics
- Algorithms & data structures with complexity awareness
- Clean, documented, consistently formatted code and reproducible builds

## Repository conventions

- One concept per folder, one small program per idea.
- Code compiles warning-free with `-Wall -Wextra`.
- Meaningful names and short comments that explain *why*, not *what*.

## Contributing

Contributions, corrections and new examples are welcome.

1. Fork the repository
2. Create a branch: `git checkout -b feature/my-topic`
3. Commit your changes: `git commit -m "Add: my topic"`
4. Push and open a Pull Request

Found a bug or a typo? Please [open an issue](https://github.com/MIhajloS07/cpp-learning-resources/issues).

## Related repositories

- 🪟 [**winforms-learning-resources**](https://github.com/MIhajloS07/winforms-learning-resources) — the C# Windows Forms learning path

## License

Released under the license found in the [LICENSE](LICENSE) file.

## Author

**Mihajlo Stoiljković** — [@MIhajloS07](https://github.com/MIhajloS07)

<p align="center"><img src="assets/divider.svg" alt="" width="100%"></p>

<p align="center"><sub>If this repository helps you, consider leaving a ⭐ — it motivates me to keep adding new material.</sub></p>
