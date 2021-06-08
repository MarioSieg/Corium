![](https://img.shields.io/codacy/grade/34055444cb164f28ab2f3978a73cab56?style=flat-square)
![](https://img.shields.io/tokei/lines/github/mariosieg/nominax?style=flat-square)
![](https://img.shields.io/github/license/mariosieg/nominax?style=flat-square)
![](https://img.shields.io/github/commit-activity/m/MarioSieg/NominaxRuntime)

# Corium Programming Language
<h4>
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
</h4>

<h2> Nominax Runtime </h2>
<h4>
Nominax is the runtime environment for Corium.<br>
It supports heavy parallelism, JIT compiling and garbage collection out of the box.<br>
  
The source code is in the [Nominax](https://github.com/MarioSieg/Corium/tree/master/Nominax) directory.
For more technical information, check out the Nominax [ReadMe](https://github.com/MarioSieg/Corium/blob/dev/Nominax/README.md).
</h4>

[Trello Board](https://trello.com/b/QiBdAQrb/nominax)

# Corium To-Go :coffee:
<h2>Short cheat sheet for the basics</h2>

<h3> Primitive Data Types </h3>
There are 5 primitive data types in Corium:<br>

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
* The equivalent in other C style languages would be “long”.

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

<h3>Local Variables</h3>
We've just learned the primitive data types.
In Corium, local variables are declared by the follow scheme:

```
let <VariableName> <Type?> = <Literal?>
```
Let's create some local variables using the
```let```
keyword:

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

```Main```
function.
So let's follow the tradition and start with hello world:

```
main () {
    print("Hello, World")
}
```

Methods and functions are declared by the following scheme:

```
<FunctionName> ( <Parameters> ) <ReturnType> {

}
```

Let's write a function which takes no parameters and returns nothing:

```
sayHello () {
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
getNumber () int {
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
