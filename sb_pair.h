
#ifndef _SB_PAIR_H_
#define _SB_PAIR_H_

namespace sb {
    template <typename FirstType, typename SecondType> 
    class pair {
    public:
        pair(): first(FirstType()), second(SecondType()){}
        
        pair(const FirstType& left, const SecondType &right): first(left), second(right) {}
        
        template<typename __FirstType__, typename __SecondType__> 
        pair(const pair<__FirstType__, __SecondType__>& rhs) : first(rhs.first), second(rhs.second){}

        template<typename __FirstType__, typename __SecondType__>
        pair<FirstType, SecondType>& operator = (const pair<__FirstType__, __SecondType__>& rhs) 
        {
            first = rhs.first;
            second = rhs.second;
            return *this;
        }

        void swap(pair<FirstType, SecondType> &rhs) 
        {
            if (this != &rhs) {
                FirstType firsttmp = rhs.first;
                rhs.first = first;
                first = firsttmp;

                SecondType secondtmp = rhs.second;
                rhs.second = second;
                second = secondtmp;
            }
        }
        
        FirstType   first;
        SecondType  second;
    };

    template <typename FirstType, typename SecondType>
    inline bool operator == (const pair<FirstType, SecondType> &left, const pair<FirstType, SecondType> &right)
    {
        return left.first == right.first && left.second == right.second;
    }

    template <typename FirstType, typename SecondType>
    inline bool operator != (const pair<FirstType, SecondType> &left, const pair<FirstType, SecondType> &right)
    {
        return !(left == right);
    }

    template <typename FirstType, typename SecondType>
    inline bool operator < (const pair<FirstType, SecondType> &left, const pair<FirstType, SecondType> &right)
    {
        return left.first < right.first || (!(left.first > right.first) && left.second < right.second);
    }

    template <typename FirstType, typename SecondType>
    inline bool operator > (const pair<FirstType, SecondType> &left, const pair<FirstType, SecondType> &right)
    {
        return right < left;
    }

    template <typename FirstType, typename SecondType>
    inline bool operator <= (const pair<FirstType, SecondType> &left, const pair<FirstType, SecondType> &right)
    {
        return !(right < left);
    }

    template <typename FirstType, typename SecondType>
    inline bool operator >= (const pair<FirstType, SecondType> &left, const pair<FirstType, SecondType> &right)
    {
        return !(left < right);
    }

    template <typename FirstType, typename SecondType>
    inline pair<FirstType, SecondType> make_pair(const FirstType& x, const SecondType &y) 
    {
        return pair<FirstType, SecondType>(x, y);
    }
};

#endif