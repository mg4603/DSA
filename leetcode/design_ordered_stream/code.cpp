#include <iostream>
#include <assert.h>

#include <vector>

class OrderedStream {
    std::vector<std::string> stream;
    int ptr;
    int stream_size;
public:
    OrderedStream(int n) 
    {
        stream = std::vector<std::string>(n, "");
        ptr = 0;
        stream_size = n;
    }
    
    std::vector<std::string> insert(int idKey, std::string value) 
    {
        stream[idKey - 1] = value;
        std::vector<std::string> out;
        while(this->ptr < this->stream_size && this->stream[this->ptr] != "")
        {
            out.push_back(this->stream[this->ptr++]);
        }
        return out;
    }
};




int main()
{
    OrderedStream* obj = new OrderedStream(5);
    {
        int idKey = 3;
        std::string value = "ccccc";
        std::vector<std::string> param_1 = {};
        assert(obj->insert(idKey, value) == param_1);
    }
    {
        int idKey = 1;
        std::string value = "aaaaa";
        std::vector<std::string> param_1 = {"aaaaa"};
        assert(obj->insert(idKey, value) == param_1);
    }
    {
        int idKey = 2;
        std::string value = "bbbbb";
        std::vector<std::string> param_1 = {"bbbbb", "ccccc"};
        assert(obj->insert(idKey, value) == param_1);
    }
    {
        int idKey = 5;
        std::string value = "eeeee";
        std::vector<std::string> param_1 = {};
        assert(obj->insert(idKey, value) == param_1);
    }
    {
        int idKey = 4;
        std::string value = "ddddd";
        std::vector<std::string> param_1 = {"ddddd", "eeeee"};
        assert(obj->insert(idKey, value) == param_1);
    }

    return 0;
}