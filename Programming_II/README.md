**Programming II -** This course uses C++ to focuses on the imperative and object-oriented styles using Abstract Data Types. Basic data structures such as stacks, queues, trees, and heaps are covered. Other topics include: recursion, basic notions of algorithmic efficiency and performance analysis in the context of sorting algorithms, and basic Object-Oriented techniques.

Topics reinforced in labs are given below with a brief description. 
<br/> 
<br /> 
<br /> 
**BinarySearchTree:** A dictionary program which read in the words and their corresponding definitions from a file placing them into a dictionary entry object and then arch object into a binary search tree. User can query the dictionary in various ways.

**DriversLicenseRecords:**  Reads a file that contains driver's license information, store the data
in a dynamically allocated array, and process interactive queries on this data.

**KnightsTourRecursion:** Implementation of a recursive backtracking solution to the Knight's Tour problem. Takes in parameters m, n, initial-knight-row, initial-knight-col from the argvcommands. Makes sure the board size is at least 1x1, and makes sure the initial position of the knight is within the board. Attempts to solve the problem and report whether a solution was found. Then prints the final board, indicating the exact sequence of moves taken.

**LinkedList:** Using pointers to create and use linked structures. Create a container class called Node, that will house a single int and a pointer to another node. The pointer will act as a link between two nodes. Creates a LinkedList class that will create lists or a series of nodes and allow us to interact with the list in various ways.

**PokemonGame:** This is a two player game where two pokemon objects are created and fight each other to the death or to the draw. Each player will get to define the name, hp, attack level, and defense level for their pokemon object. After each player makes a monster, randomly decide who goes first using a 2-sided die object, then they will fight for a maximum of 10 rounds. If either player dies during the game, the game must stop. If they are both standing at the end, it's a draw.

**PostfixPrefixInfixExpressions:** Program will prompt for and read a series of strings from the console and test whether each represents a valid postfix expression. The strings will have no embedded blanks and will contain some combination of the standard operators (+, -, *, /) and identifiers (single alphabetic characters that are to be treated, like C++ and Java, as being case-sensitive). If any other character detected during parsing, rejects the string as syntactically invalid. Continue prompting for strings until the user enters a single # at the prompt.

**SortingAlgorithms:** Used to investigate the performance of various sorting algorithms on several datasets, evaluate them using Big-O notation, and produce tables and graphs of actual measured execution times.

**Stack&Queue:** Program also known as Lydia's Lattes. As customers arrive, they are added to Lydia's queue. The person at the head of the queue is the one Lydia is currently serving. If a VIP comes along while another customer is being served, Lydia stops serving that person and switches to the VIP. If a more important VIP comes along, Lydia suspends working on the current VIP and starts on the more important one. When Lydia finishes with a customer, the VIP most recently suspended, if any, resumes being served. If no lesser VIPs are waiting, then the person at the head of the queue resumes being served. If a VIP is being served, and another (but lesser) VIP arrives, that person simply walks away so as to not upset anything going on.

**Stacks:** This lab is a primer for creating an interface as well as continuing to utilize inheritance. This lab contains one interface, StackInterface, which will contain the pure virtual methods that form a obligation to the inheriting class to implement.
