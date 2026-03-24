## Notes

- Time complexity based on input size

    <img width="508" height="228" alt="image" src="https://github.com/user-attachments/assets/060a46da-fbab-43ef-869b-91f10aa490e8" />

### Sorting
- Bubble sort : O(n^2)
- Merge sort : O(nlogn)
- Counting sort: O(n)
- sort in increasing order:

  <img width="429" height="85" alt="image" src="https://github.com/user-attachments/assets/66b7fad4-d792-4e1d-836f-79759bf760ec" />
- sort in decreasing order:

  <img width="327" height="50" alt="image" src="https://github.com/user-attachments/assets/c26a6873-430b-4612-91a9-4d75c516622c" />

### Binary search
- lower_bound
- upper_bound


### Number of theory
- prime:

  - The prime factorization of a number N can be denoted as:

    <img width="204" height="49" alt="image" src="https://github.com/user-attachments/assets/f4286af2-3d18-44a4-aa74-5602dec39ac1" />
  - Here, p1, p2, p3... are primes and alphas's are positive numbers. 
  <img width="536" height="219" alt="image" src="https://github.com/user-attachments/assets/4c5649f4-79d4-4ca7-b90d-7c690ce065d2" />
- Sieve of Eratosthenes:

  - It is a preprocessing algorithm that builds an array, using which we can effectively check if a given number between 2 and n is prime and, if it is not, find one prime factor of a number.
  - The value a[k]=0 means that k is prime, and the value a[k]!=0 means that k is not a prime number and one if its prime factor is a[k].
  - code:

    <img width="790" height="203" alt="image" src="https://github.com/user-attachments/assets/8b705095-6b4f-4794-be78-ec91e8a67743" />
  - Time complexity: O(nloglogn)
    
- Euclid's algorithm:

  - The greatest common divisor of numbers a and b, gcd(a,b), is the greatest number that divides both a and b, and the least common multiple of a and b,
    lcm(a,b), is the smallest number that is divisible by both a and b. 
  - The GCD and LCM are connected as:

    <img width="233" height="75" alt="image" src="https://github.com/user-attachments/assets/0e70a91f-9c1a-4fe7-b446-2dbfef969a0e" />
  - Euclid's algorithm provides an efficient way to find the greatest common dividor of 2 numbers. The algorithm is based on the following formula:

    <img width="365" height="80" alt="image" src="https://github.com/user-attachments/assets/1e96c62d-9afa-49f3-8fc2-5d17f271e5af" />
  - Time complexity: O(logn)
    
- Euler's totient function:

  - Numbers a and b are coprime if gcd(a,b)=1. Euler's totient function gives the number of coprime numbers to n between 1 and n.
  - The value of Euler's totient function can be calcualtes from the prime factorization of n using the formula:

    <img width="235" height="75" alt="image" src="https://github.com/user-attachments/assets/2a0ebe46-1c82-4bb8-a780-c42368ed8e03" />
    
- Modular Arithmetic:

  - The following formulas can be used:

    <img width="490" height="124" alt="image" src="https://github.com/user-attachments/assets/eb40f672-928d-4f5f-8b88-423dee975f1a" />
  - Modular exponentiation:

    - The implementation:
 
      <img width="275" height="115" alt="image" src="https://github.com/user-attachments/assets/a951ebab-c758-443b-80ee-86101e08a9ff" />
      <img width="584" height="192" alt="image" src="https://github.com/user-attachments/assets/f7f75a8e-2cec-4103-b45e-8f5a484729d4" />
    - Time complexity: O(logn)
  
  - Fermat's theorem and Euler's theorem:

    <img width="761" height="359" alt="image" src="https://github.com/user-attachments/assets/8c28504d-3488-44bf-b2f0-5b7bce0c215f" />
    
- Diophantine equation:

  - A Diophantine equation is an equation of the form:

    <img width="161" height="46" alt="image" src="https://github.com/user-attachments/assets/b074d3a8-2e94-40c1-b42c-adadedb5f4ea" />
  - We can solve a Diophantine equation by using Euclid's algorithm. We can extend Euclid's algorithm so that it will find numbers a and y that satisfy the following equation:
 
    <img width="195" height="42" alt="image" src="https://github.com/user-attachments/assets/d997c353-5e3f-4a0a-98cb-1c98bee92a06" />
  - The equation can be solved if c is divisible by gcd(a,b) and otherwise the equation cannot be solved. 
    
- Lagrange's theorem:

  - It states that every positive integer can be represented as a sum of 4 squares, i.e., a^2 + b^2 + c^2 + d^2. 
- Zeckendrof's theorem:

  - It states that every positive integer has unique representation as sum of fibonacci numbers such that no 2 numbers are equal or consecutive fibonacci numbers. 
- Wilson's theorem:

  - It states that a number n is prime exactly when:
 
    <img width="215" height="48" alt="image" src="https://github.com/user-attachments/assets/d5eadb81-91a6-4254-a0c9-1b6ffd7d94f7" />

### Combinatorics:
- A combinatorial problem can often be solved using a recursive function.
- Binomial cofficients:

  - The binomial coefficient nCk equals the number of ways we can choose a cubset of k elements from a set of n elements.
  - The below are some of the formulas:

    1. Binomial coefficients can be recursively calculated as follows:
 
       <img width="248" height="82" alt="image" src="https://github.com/user-attachments/assets/1ad16de9-3ee2-441a-a938-ef04ddfef899" />

       - nCk = (n-1)C(k-1) + (n-1)Ck 
    2. Another way to calcualte binomial coefficient is:
 
      <img width="187" height="77" alt="image" src="https://github.com/user-attachments/assets/8593b0b3-1665-475a-a605-260cb1d47662" />
 
  - Properties:
 
    1. 
    <img width="176" height="84" alt="image" src="https://github.com/user-attachments/assets/70c944da-36aa-4650-ba35-9efb8e30b6aa" />

    2. The sum of binomial coefficients is:
   
       <img width="317" height="74" alt="image" src="https://github.com/user-attachments/assets/da899882-d5b3-41ff-a26e-6ef51f772637" />
    3. The reason for the name "binomial coefficient" is that:
   
       <img width="592" height="79" alt="image" src="https://github.com/user-attachments/assets/f9fa3d23-ad99-430b-9956-47e24521e054" />
    4.Binomial coefficients also appear in Pascal's triangle where each value equals the sum of 2 above values:
 
      <img width="331" height="155" alt="image" src="https://github.com/user-attachments/assets/26a0a781-d3f9-434a-928c-9246d8de76e5" />   
- Multinomial coefficient:

  <img width="320" height="82" alt="image" src="https://github.com/user-attachments/assets/7e7e22ee-aa65-439c-be29-e259ff34b9a5" />
  - The multinomial coefficient equals the number of ways we can divide n elements into subsets of sizes k1, k2, ....km, where k1+k2+...+km = n.
  - Multinomial coefficients can be seen as a generalization of binomial coefficients; if m=2, the above formula corresponds to binomial coefficient formula.

- Catalan numbers:

  - The Catalan number Cn equals the number of valid parenthesis expressions that consist of n left parentheses and n right parentheses.
  - Below are the ways/ formula's to calculate the catalan number:
    1. Catalan number can be calculated using the below formula:
 
       <img width="206" height="82" alt="image" src="https://github.com/user-attachments/assets/6a75fdba-0808-478c-bb4c-fa069968856e" />
       - The sum goes through the ways to divide the expression into 2 parts such that both parts are valid expressions and the first part is as short as possible but not empty.
       - Ci = number of ways to construct the expression using the parenthese in first part, not counting the outermost parenthese.
       - Cn-i-1 = number of ways to construct an expression using the parentheses in the second part.
       - C0=1. (base ) 
    2. using binomial coefficients:
 
       <img width="185" height="78" alt="image" src="https://github.com/user-attachments/assets/bbc8af24-2329-4369-923f-49be9f0ee489" />
  - Counting trees:

    - Catalan numbers are also related to trees:
      1. There are Cn binary trees of n nodes.
      2. there are Cn-1 rootes trees of n nodes. 
 
- Inclusion - exlcusion:

  - Inclusion-exclusion is a technique that can be used for counting the size of union of sets when the sizes of the intersection are known, and vice versa;

    <img width="269" height="39" alt="image" src="https://github.com/user-attachments/assets/647e54ae-1e9b-4028-ac22-6651ee19e999" />
    <img width="228" height="131" alt="image" src="https://github.com/user-attachments/assets/11afef67-56f9-4a2a-b8df-01a11bbd0bfe" />

  - for 3 sets:

    <img width="613" height="54" alt="image" src="https://github.com/user-attachments/assets/a11ad4f9-edd7-4a57-b6b3-44497c5c28d8" />
    <img width="320" height="218" alt="image" src="https://github.com/user-attachments/assets/3d2ae543-1598-4d27-814c-cec31992cabc" />

- Cayley's formula:

  - It states that there are n^(n-2) labeled trees that contain n nodes.
  - The nodes are labeled 1,2,...n, and 2 trees are different if either their structure or labeling is different.
  - Cayley's formula can be derived using Prufer codes.

### Game theory:
- Game states:

  - A winning state is a state where the player will win the game if they play optimally, and a losing state is a state where the player will lose the game if the opponet plays optimally.
  - It turns out that we can classify all the states of a game so that each state is either a winning state or losing state.
  - Let us consider a game where there is initially a heap of n sticks. Players A and B move alternatively, and player A begins. On each move, the player has to remove 1, 2 or 3 sticks from the heap, and the player who removes the last stick wins the game.

     <img width="730" height="121" alt="image" src="https://github.com/user-attachments/assets/ccd2a0ec-7fa4-4936-ac4b-806ab38269c3" />
   
- State graph:

  - Let us consider a game, where in each state k, it is allowed to remove any number x of sticks such that x is smaller than k and divides K.
  - The below shows the states 1...9 of game as state graph, whose nodes are states and edges are the moves between them:

    <img width="323" height="290" alt="image" src="https://github.com/user-attachments/assets/816552fe-9e2e-4308-99c9-f92a139ce89f" />
  - the classification os states is as follows:

    <img width="369" height="84" alt="image" src="https://github.com/user-attachments/assets/b47a02a7-132d-472f-9f77-a3f63708a30b" />
  
- Nim Game:

  - The nim game is a simple game that has an important role in game theory, because many other games can be played using the same strategy.
  - First, we focus on nim, and then we generalize the strategy to other games.  

- Sprague-Drundy Theorem:

  - It generalizes the strategy used in nim to all games that fulfil the following requirements:

    1. There are 2 players who move alternatively.
    2. The game consists of states, and the possible moves in a state do not depend on whose turn it is.
    3. The game ends when a player cannot make a move.
    4. The game surely ends sooner or later.
    5. The players have complete information about the states and allowed moves, and there is no randomness in the game. 

  - The idea is to calcualte for each game state a Grundy number that corresponds to the number of sticks in a nim heap. When we know the Grundy numbers for all states, we can play the game like nim game.
  - Grundy numbers:

    - The grundy number for a game state is:
 
      <img width="206" height="45" alt="image" src="https://github.com/user-attachments/assets/8e88475e-a940-4736-aad5-267363ecb7fb" />
    - where g1, g2,...gn are Grundy numbers for states to which we can move from the statte, and the mex function gives the smallest non-negative number that is not in the set.
    - If there are no possible moves in a state, its Grundy number is 0, because mex(phi) =0;
    - The Grundy number of losing state is 0, and the Grundy number of a winning state is a positive number.
     
  - Grundy's game:

    - 
  -  

### 
- 
