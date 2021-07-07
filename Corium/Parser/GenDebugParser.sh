alias antlr4='java -jar /usr/local/lib/antlr-4.9-complete.jar'
antlr4 Corium.g4
javac Corium*.java
java org.antlr.v4.gui.TestRig Corium constVariableDeclaration -tree