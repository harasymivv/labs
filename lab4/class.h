#pragma once

class BooleanVector {
private:
    bool* data;
    int size;

public:
    BooleanVector(int n);
    BooleanVector(bool* input_data, int n);
    BooleanVector();
    ~BooleanVector();
    int getSize() const;
    bool getComponent(int index) const;
    void setComponent(int index, bool value);
    int getWeight() const;
    void print_array();
    BooleanVector& operator&(const BooleanVector& other);
    BooleanVector& operator~();
};

bool* get_data_from_user(int& size);