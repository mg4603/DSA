## Compile time #3.1 Make string
Write a class template that, when instantiated with parameter pack char... C,  
will contain the static string value (null-terminated array of characters or  
pointer to such array) equals/pointing to string, containing these characters.  
All calculations should be finished at compile time. Code size limited to 1Kb.   

Test input: several parameter packs like <'H','i'> etc.

Your class template will be instantiated this way during tests:

    make_string<'H','i'>::value

Sample test cases:

    static_assert(ct_strcmp(make_string<'H','i'>::value, "Hi"), "");
    // and
    Assert::That(make_string<'H','i'>::value, Equals("Hi"));
