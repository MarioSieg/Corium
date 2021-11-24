![](https://img.shields.io/codacy/grade/34055444cb164f28ab2f3978a73cab56?style=flat-square)
![](https://img.shields.io/github/workflow/status/MarioSieg/Corium/CMake/master)
![](https://img.shields.io/tokei/lines/github/mariosieg/nominax?style=flat-square)
![](https://img.shields.io/github/license/mariosieg/nominax?style=flat-square)
![](https://img.shields.io/github/commit-activity/m/MarioSieg/NominaxRuntime)
![](https://img.shields.io/discord/866345476186046494)

# The Corium programming language
![image](https://user-images.githubusercontent.com/49988901/141957248-2dfd4b59-a416-4d90-8c56-1d6a1ef36914.png)

Corium is a modern, fast and simple scripting language,<br>
empowering easy but powerful programming with high performance.<br>
A language for everyone for everything.<br>
<br>

The goal is to create a new programming language,<br>
which is easy to learn for new developers and<br>
for developers comming from other languages.
The language is also very flexible and fast<br>
thus a good choise for many different projects.<br>

<br>
<h2> Core features </h2>

* Simple
* Safe and test driven
* Statically typed with type inference
* Builtin parallelism using the ```parallel``` keyword
* Builtin GPU computing using the ```compute``` keyword
* Fast scripting and prototyping
* Cross-platform
* Workspace system for complex projects
* Simple but powerful types
* Builtin package manager

<br>
<h2> The project </h2>

The project was started around February in 2021,<br>
to create a new programming language for the world.<br>
A language for beginners and experts, for desktop and mobile.<br>
Trying to unite different tech-stacks.<br>
This year (2021/2022) I will participate with Corium as my project in [Jugend Forscht](https://www.jugend-forscht.de/),<br>
a German science competition.<br>


I was always bugged by the two language problem:<br>
If you write your code in a simple and high level language,<br>
the productivity will be high but not the performance.<br>
Of course the performance in enough in most cases,<br>
but many performance critical parts are often implemented in a fast language such as C, C++ or Rust.<br>
This is very error prone and requires much more effort from the development team.<br>
There are existing approaches for a simple and fast programming language,<br>
but they are all komplex languages themselves.<br>
Corium aims to just be simple and fast,<br>
using a clean and consistent syntax and a "friendly" compiler.<br>
In my opinion, many languages are too bloated in features,<br>
having multiple ways to do the same thing.<br>

<br>
<h2> Development state </h2>
Corium is in an early development stage.<br>
The compiler is currently prepared for an alpha release,<br>
with basic but solid features.<br>
The Alpha will be available in the next Months for testing and feedback purposes.<br>

<br>
<h2> Support </h2>

If you want to support the project,<br>
feel free to contribute or suggest any idea you would like.<br>
You can also support the project without development, by [sponsoring](https://github.com/sponsors/MarioSieg)!<br>

<br>
<h2> Infrastructure </h2>

[Corium IntelliJ IDEA Plugin](https://plugins.jetbrains.com/plugin/17850-corium)
Also works with CLion, WebStorm, Rider and any other IDEA based IDE.<br>
[Discord Server](https://discord.gg/crEub5ckVK)
Join our small and friendly community. Everyone is welcome!

<br>
<h2> Implementation </h2>

The two primary components are:
* [The Corium compiler](https://github.com/MarioSieg/Corium/tree/dev/Corium/Projects)
* [The Nominax runtime system](https://github.com/MarioSieg/Corium/tree/dev/Nominax)

<br>
<h2> Sponsors </h2>

A special thanks to all of my sponsors!<br>
Thank you very much for supporting my work,
this gives me a lot of motivation.<br>
Sponsors in chronological order:<br>

* Jean Igrec https://github.com/Jigrec
* Andreas Partsch https://github.com/4ndre4s
* Kevin Sieg https://github.com/KevinSieg

<br>
<h2> Corium preview </h2>
"Talk is cheap. Show me the code." ― Linus Torvalds<br>
Code snippets in Corium to get a quick overview.<br>

<br>
<h3> Idiomatic conventions </h3>

* No semicolons - new line per statement
* Keywords are **lowercase**
* Mutable variables are **lowerCamelCase**
* Immutable variables are **SCREAMING_CASE**
* Types and classes are **UpperCamelCase**
* Functions and methods are **lowerCamelCase**
* Interfaces are **IUpperCamelCase** with an **I** as prefix
* Modules are **lowercase**
* Source file names are **lowercase** with the **.cor** file extension

<br>
<h3> Primitive Data Types </h3>
There are 4 primitive data types in Corium.<br>
Choosing a type is easy, each primitive type has exactly one purpose.<br><br>

**```int```**
* A 64-bit signed integer.
* Can hold values from -9223372036854775808 to 9223372036854775807.
* Because it it signed, it can also hold negative values.
* This type is used as the default type for natural number calculations.
* The equivalent in other C style languages is *long*.

**```float```**
* 64-bit double precision float.
* Can hold values from -2.22507•10−308  to approximately 1.79769•10308.
* This type is used as the default type for real number calculations.
* The equivalent in other C style languages is *double*.

**```bool```**
* A boolean type.
* Can either be true (1) or false (0).

**```char```**
* A 32-bit unsigned UTF-32 encoded character.
* Can hold any unicode codepoint.

<br>
<h3> Advanced Data Types </h3>
Corium contains multiple advanced data types and structures.<br>
These are implemented in the standard library, but the most important ones are<br>
auto-imported into each file.<br>

* ```String```
* ```List```
* ```Option```
* ```Result```
* ```BigInt```
* ```BigFloat```
* ```Object```

<br>
<h3> Comments </h3>

```
# This is a single line comment
```

```
#! This
is
a multi line
comment
!#
```

```
#@ This is a doc-comment which will appear in the generated documentation.
```

<br>
<h3> Hello, world! </h3>

The Corium hello world is a one-liner:<br>
```
print("Hello, world")
```
The print() function is used to print text to the console.<br>
A new line is appended by default.<br>

<br>
<h3> Variables </h3>
In general, the identifier is written before the type.<br>
For most cases, the type is inferenced from the expression:<br>

| Expression    | Inferred type
| ------------- |:-------------:|
| 10            | int           |
| 0.5           | float         |
| true          | bool          |
| 'C'           | char          |
| "Muffins"     | String        |
| new MyClass() | MyClass       |

Of course the type can be explicitly specified.<br>
So<br>
**A:**
```
let x = 10
```
is seen by the compiler as<br>
**B:**
```
let x int = 10
```
In most cases, letting the compiler infer the types is the way to go. (**A**)<br>
But sometimes, extra type information can be beneficial. (**B**)<br>
<br>

Mutable variables are defined using the ```let``` keyword.<br>
They also use *lowerCamelCase* as naming convention.<br>

```
let num = 10
let time = 23.45
let food = "Burger"
```

Immutable variables are defined using the ```const``` keyword:<br>
They also use *SCREAMING_CASE* as naming convention.<br>

```
const IS_DEBUG = true
const PI = Math.atan2(1.0, 1.0) * 4.0
const FAVOURITE_FOOD = "Lasagne"
```

<br>
<h3>Functions</h3>

Functions are defined using the ```function``` keyword.<br>

A simple function without a parameter or return type:<br>
```
function simple() {

}
```

A function with a ```float``` **x** as parameter but no return type:<br>
```
function simple(x float) {

}
```

A function with a ```float``` **x** as parameter, return type of type ```float``` and a ```return``` statement:<br>
```
function square(x float) float {
    return x * x
}
```

<br>
<h3>Conditionals</h3>

A simple ```if```-statement:<br>
```
let isSunshine = true

if isShunshine {
    print("Let's go to the beach")
}
```
For chained conditions the ```and```, ```or``` and ```not``` operators are used.<br>

An ```if```-statement with a chained condition:<br>
```
let isSunshine = true
let isSummer = true
let temperate = 20

if isShunshine or isSummer and not temperature < 18 {
    print("Let's go to the beach")
}
```

```if```-statements can also be chained using ```else``` and ```else if```<br>

A chained ```if```-statement with an ```else``` block:<br>
```
let isSunshine = true

if isShunshine {
    print("Let's go to the beach")
} else {
    print("It's raining, let's play some games instead")
}
```

A chained ```if```-statement with an ```else if``` and ```else``` block:<br>
```
let isSunshine = true
let temperate = 20

if isShunshine {
    print("Let's go to the beach")
} else if not temperate < 15  {
    print("Let's go for a walk")
} else {
    print("It's raining, let's play some games instead")
}
```

For long and complex comparisons,<br>
the ```compare``` statement can be used.<br>
It resembles a switch-statement from C-like languages,<br>
but is much more powerful.<br>
```
let grade = 'C'

compare grade {
    'A' => print("Easy"),
    'B' => print("Very good!"),
    'C' => print("It's okay"),
    'D' => print("I'll do better next time"),
    'E' or 'F' => print("Let's try that again"),
    else => print("Grades must be from A to F!")
}
```
