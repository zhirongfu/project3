#pragma once
#include "Post.hpp"
#include <vector>
#include <string>

template <typename T>
class Network
{
private:
    T *accounts[200];
    int acc_cnt;
    std::vector<Post> posts;

    int getIndexOf(const std::string &) const;

public:
    Network();

    // bag functions
    int getSizeOfNetwork() const;
    bool isEmpty() const;
    bool containsAccount(T *) const;

    // mutators
    bool addAccount(T *);
    bool removeAccount(T *);
    void clear();

    void populateNetwork(const std::string);

    Network &operator-=(const Network &);

    bool authenticateFollow(T &acc, const std::string &);

    bool addToFeed(Post &p);

    void printFeedForAccount(T &acc);
};
