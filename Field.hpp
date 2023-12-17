#ifndef FIELD_H 
#define FIELD_H
#include<string>
class Field 
{
    private:
        int* cells;
        bool* checked;
        int size;
        int num_mines;
    public:
        Field();

        Field(int size, int num_mines);

        ~Field();

        std::string to_string() const;

        std::string answer_string() const;

        std::string empty_layout_string()const;

        int get_size() const;

        int get_num_mines() const;

        int neighbor_mines(int ind) const;

        void mark_checked(int ind);

        bool is_checked(int ind) const;
        
        bool has_mine(int ind) const;
};
#endif