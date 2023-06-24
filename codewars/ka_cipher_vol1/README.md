## Ka Ka Ka cypher - words only vol 1

### Task:
Write a function that accepts a string word and returns encoded message using  
ka cipher.  

### Rules:
* The encoded word should start from ka.
* The ka goes after vowel(a,e,i,o,u)
* When there is multiple vowels together, the ka goes only after the last vowel  
* When the word is finished by a vowel, do not add the ka after.  

### Input/Output:  
The word string consists of only lowercase and uppercase characters.  There is  
only 1 word to convert - no white spaces.  

### Example:
    "a" => "kaa"
    "ka" => "kaka"
    "aa" => "kaaa"  
    "Abbaa" => "kaAkabbaa"
    "maintenance" => "kamaikantekanakance"
    "Woodie" => "kaWookadie"
    "Incomprehensibilities" => "kaIkancokamprekahekansikabikalikatiekas"

