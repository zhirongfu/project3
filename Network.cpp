#include "Network.hpp"
#include "Account.hpp"
#include <iostream>
#include <fstream>
#include <cctype>

template <class T>
Network<T>::Network()
{
    acc_cnt = 0;
}

template <class T>
int Network<T>::getIndexOf(const std::string &usr_name) const
{

    for (int i = 0; i < acc_cnt; i++)
    {
        if (accounts[i]->getUsername() == usr_name)
            return i;
    }

    return -1;
}

template <class T>
int Network<T>::getSizeOfNetwork() const
{
    return acc_cnt;
}

template <class T>
bool Network<T>::isEmpty() const
{
    return acc_cnt == 0;
}

template <class T>
bool Network<T>::containsAccount(T *acc) const
{
    return getIndexOf(acc->getUsername()) != -1;
}

// mutators

template <class T>
bool Network<T>::addAccount(T *acc)
{
    if (acc_cnt >= 200 || getIndexOf(acc->getUsername()) != -1)
        return false;

    accounts[acc_cnt++] = acc;

    acc->setNetwork(this);
    return true;
}

template <class T>
bool Network<T>::removeAccount(T *acc)
{
    int idx = getIndexOf(acc->getUsername());
    if (idx == -1)
        return false;

    for (int i = idx; i < acc_cnt - 1; i++)
    {
        accounts[i] = accounts[i + 1];
    }
    acc_cnt++;
    return true;
}

template <class T>
void Network<T>::populateNetwork(const std::string filename)
{
    std::ifstream in(filename);

    while (true)
    {
        std::string line;
        getline(in, line);
        if (line == ";")
            break;

        if (in.eof())
        {
            std::cout << "Improper Format\n";
            return;
        }

        in.ignore();

        int space_indx = -1;
        for (int i = 0; i < line.size(); i++)
        {
            if (isspace(line[i]))
            {
                if (space_indx == -1)
                    space_indx = i;
                else
                { // more than one space in one line
                    std::cout << "Improper Format\n";
                    return;
                }
            }
        }

        if (space_indx == -1)
        { // no spaces in the line
            std::cout << "Improper Format\n";
            return;
        }

        std::string usr = line.substr(0, space_indx);
        std::string pass = line.substr(space_indx + 1);

        T *acc = new T(usr, pass);

        addAccount(acc);
    }

    in.close();
}

template <class T>
Network<T> &Network<T>::operator-=(const Network<T> &other)
{
    for (int i = 0; i < acc_cnt; i++)
    {
        int other_idx = other.getIndexOf(accounts[i]->getUsername());
        if (other_idx != -1)
        {
            removeAccount(other.accounts[i]);
        }
    }
    return *this;
}
template <class T>
bool Network<T>::authenticateFollow(T &acc, const std::string &to_follow)
{

    if (getIndexOf(acc.getUsername()) == -1 || getIndexOf(to_follow) == -1)
        return false;

    return acc.followAccount(to_follow);
}
template <class T>
bool Network<T>::addToFeed(Post &p)
{

    if (getIndexOf(p.getUsername()) == -1)
        return false;

    posts.push_back(p);
    return true;
}

template <class T>
void Network<T>::clear()
{
    acc_cnt=0;
    posts.clear();
}

template <class T>
void Network<T>::printFeedForAccount(T &acc)
{

    auto following = acc.viewFollowing();

    for (Post &p : posts)
    {

        for (std::string &f : following)
        {
            if (f == p.getUsername())
            {
                p.displayPost();
                break;
            }
        }
    }
}

template class Network<Account>;
