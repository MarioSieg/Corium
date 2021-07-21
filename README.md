![](https://img.shields.io/codacy/grade/34055444cb164f28ab2f3978a73cab56?style=flat-square)
![](https://img.shields.io/github/workflow/status/MarioSieg/Corium/CMake/master)
![](https://img.shields.io/tokei/lines/github/mariosieg/nominax?style=flat-square)
![](https://img.shields.io/github/license/mariosieg/nominax?style=flat-square)
![](https://img.shields.io/github/commit-activity/m/MarioSieg/NominaxRuntime)

# Corium Programming Language

Corium is a modern scripting language for all platforms.<br>
The goal is to have a safe, clean and easy to write scripting language,<br>
which is still very fast, so it can be used for AI, HPC or game development.<br>
The final features of the language are:<br><br>

* Easy to learn
* Clean syntax
* Safe, statically typed
* Test driven development
* Fast prototyping
* Parallel keyword for automatic parallelism
* Offload keyword for automatic GPGPU
* Cross-platform development
* Builtin formatter
* Builtin package installer
* Fast

The source code for the language parser is in the [Corium](https://github.com/MarioSieg/Corium/tree/master/Corium) directory.

<h2> Why another language? </h2>

As you might know,<br>
there are already plenty of programming languages out there.<br>
Many programming can be divided into two groups (the so called two language problem):<br>
There are very high level languages such as Python or Java and<br>
many performance critical code is written in a more lower level language <br>
such as C, C++ or Rust. This is highly inefficient as it requires more knowledge,<br>
testing and time. Of course it is also more error prone.<br>
Corium allows for code which is clean, portable, easy to write and still very fast.<br>
With semicolons and an easy to read C-like syntax, Corium is easy to learn.<br>
The core language features are enough for all kinds of projects, but not too much to become bloated.<br>
It has a great and easy to use debugger, package manager and linter.<br>
Just get your favourite editor like VisualStudioCode, IntelliJ or something else,<br>
and start coding!<br>
It's also fairly easy to embed Corium into an existing C++ application.<br>
Corium also is used as a game scripting language in one of my custom engines.<br>

<h2> What's the current state of Corium? </h2>
Corium is currently under heavy development.<br>
Nominax (the runtime system) is ready for simple Corium programs.<br>
The primary focus lies on the frontend language lexer and code generator.<br>
In some weeks, it is expected to have a first working version,<br>
which can be used to write simple code in Corium.<br>
This is a big step, from that point on features will come in quickly.<br>
That's why we need you!<br>
Consider to contribute or sponsor the project!<br>
Let's make Corium a widely used, beginner friendly and fast language!<br>

<h2> Nominax Runtime </h2>
<h4>
Nominax is the runtime environment for Corium.<br>
It supports heavy parallelism, JIT compiling and garbage collection out of the box.<br>

The source code is in the [Nominax](https://github.com/MarioSieg/Corium/tree/master/Nominax) directory.
For more technical information, check out the Nominax [ReadMe](https://github.com/MarioSieg/Corium/blob/dev/Nominax/README.md).
</h4>

<h2> Sponsors </h2>
<h4>
A special thanks to all of my sponsors!<br>
Thank you for supporting my work,
this gives me a lot of motivation.<br>
Sponsors in chronological order:<br>

* Jean Igrec https://github.com/Jigrec
* Andreas Partsch https://github.com/4ndre4s

</h4>

<h2> Roadmap </h2>

[Trello Board](https://trello.com/b/QiBdAQrb/nominax)

# Corium To-Go :coffee:
<h2>Short cheat sheet for the basics</h2>

<h3> Primitive Data Types </h3>
There are 4 primitive data types in Corium:<br>

* int
* float
* bool
* char

The number types ```int``` and ```float```<br>
are 64 bits wide and provide enough range and precision for all tasks.<br>
Corium empowers static typing for safety and explicit code,<br>
and choosing the type is very simple.<br>
Every of the 4 primitive type is perfect for<br>
some specific type of data.<br>

<h4>int</h4>

* A 64-bit signed integer.
* Can hold values from -9223372036854775808 to 9223372036854775807.
* Because it it signed, it can also hold negative values.
* This type is used as the default type for natural number calculations.
* The equivalent in other C style languages is “long”.

<h4>float</h4>

* 64-bit double precision float.
* Can hold values from -2.22507•10−308  to approximately 1.79769•10308.
* This type is used as the default type for real number calculations.
* The equivalent in other C style languages is "double".

<h4>bool</h4>

* A boolean type.
* Can either be true (1) or false (0).

<h4>char</h4>

* A 32-bit UTF-32 character.
* Can hold **any** unicode codepoint.

<h3>Comments</h3>

Comments in Corium begin with a ```#```, like in Python:<br>

```
let x = 10 # This is a comment, x is of type int!
```

Multiline comments are written using two ```##``` for the begin and the end:
```
##
    This is a
    long long,
    long
    multiline comment.
##
let x = 10
```

<h3>Local Variables</h3>
We've just learned the primitive data types.
In Corium, local variables are declared by the follow scheme:

```
let <VariableName> <Type?> = <Literal?>
```
Let's create some local variables using the
```let```
keyword. No semicolons required!<br>

```
let a int = 3
let b float = 2.5
let c char = 'O'
let d bool = true
```
If you look at the above scheme again,<br> the ```Type```
and the ```Literal```
are optional (indicated by the
```?```).<br> That means that we can elide them:

```
let a = 3
let b = 2.5
let c = 'O'
let d = true
```

That's better right?<br>
Corium knows the type from the literal,
so types can be deduced:
| Literal  | Deduced Type |
| ------------- | ------------- |
| 3  | int  |
| 2.5  | float  |
| 'O'  | char  |
| true  | bool  |

<h3> Functions And Methods </h3>
Like in many other languages,
every program starts in within the

```main```
function.
So let's follow the tradition and start with hello world:

```
fun main () {
    print("Hello, World")
}
```

Methods and functions are declared by the following scheme:

```
fun <FunctionName> ( <Parameters> ) <ReturnType> {

}
```

As you can see above, functions are declared using the ```fun``` keyword.
Let's write a function which takes no parameters and returns nothing:

```
fun sayHello () {
    print("Say hello to my little friend!")
}
```

in C we would write this function like this:

```
void sayHello () {
    printf("Say hello to my little friend!\n");
}
```

this also applies to many other languages deriving from C such as C++, Java or C#,<br>
but of course the priting mechanism is different.<br>
Lets write another functions which returns a number:<br>

```
fun getNumber () int {
    return 5
}
```

Let's write it again in C:

```
int getNumber() {
    return 5;
}
```

As you can see, the return type is just at a different position and there are no semicolons.<br>
If your functions returns nothing, the return type is just elided.<br>
There is no need to write ```void``` like we know it from C style languages.<br>

Parameters are written in the following scheme:<br>

```
<ParameterType> <ParameterName>
```

A simple square function could look like:

```
fun square (float x) float {
    return x * x
}
```

This function has a parameter ```x``` of type ```float```<br>
and has a return value of type ```float``` too.

To invoke a function the ```()``` call operator is used.<br>
Arguments are submitted inside the parenthesis:<br>
```
let y = square(2.0)
# Now y is 4.0
```

<h3>Conditionals</h3>

In Corium, the classic ```if``` statement which executes code<br>
if the expression is true, is written using the following scheme:

```
if <Expression> {
    <Body?>
}
```

The same applies to ```else if```.<br>
A big difference to C is that there are **no parenthesis** ```()``` around the if-expression.<br>
But the **curly braces** ``` { } ``` are **always enforced**.<br>

Corium provides following comparison operators:<br>

| Operator | Meaning |
| ------------- | ------------- |
| == | equal to  |
| != | not equal to  |
| <  | less than  |
| >  | greater than |
| <=  | less or equal to  |
| >=  | greater or equal to  |

A simple ```if```-statements which checks if the variable ```x``` of type ```int``` equals **10** could look like:<br>

```
let x = 10
if x == 10 {  # Will be true
    print("x is 10!")
}
```

To execute code when the expression in the ```if```-statement is false,<br>
a simple ```else``` block can be used:<br>

```
let x = 5
if x == 10 { # Will be false
    print("x is 10!")
} else {
    # Instead this code will be executed, because ```5 == 10``` is false!
    print("x is not 2!")
}
```

Using the final combination of ```if``` and ```else```,<br>
```else if``` statements can be used.<br>
These executed if the previous ```if``` statement did not execute,<br>
because the condition was false: <br>

```
let x = 2

if x == 0 {
   print("x is 0!")
} else if x == 1 {
   print("x is 1!")
} else if x == 2 { 
    print("x is 2!")
} else {
    print("x is something else!")
}
```

The most powerful statement is the ```compare``` statement.<br>
The following scheme is used:<br>
```
compare <Expression> { 
    <Body?>
}
```
It is somewhat similar to the ```switch``` statement in C, but much more powerful.<br>
A ```compare``` statement is made out of multiple arms. For each arm the scheme is:<br>

```
<Expression> | else => <Body?>
```

A simple example:

```
let x = 3
compare x {
    0 => print("x is 0!")
    1 => print("x is 1!")
    2 => print("x is 2!")
    3 => print("x is 3!")
    else => print("x is something else!")
}
```

Each "arm" act's like a ```if``` statements:<br>
The first arm ``0 => print("x is 0!")``` is the same as:<br>

```
if x == 0 {
    print("x is 0!")
}
```

If ```x``` is zero, print ```x is 0!```.
The following arms are like ```else if``` statements<br>
and the final arm ```else => print("x is something else!")``` acts exactly like a normal else statement:<br>
if none of the above conditions occured, print ```x is something else!```!
In fact, it's possible to write the whole ```compare``` statement<br>
using linked ```if else``` statements, but that's ugly and far less clean.<br>

<h3>Loops</h3>
Comming soon...
