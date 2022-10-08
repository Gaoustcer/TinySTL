namespace myname{
    // typedef typename T valuetype;
    template<typename T> class myC{
    public:
        myC();
        ~myC();
        typedef const T* Tconst;
        // using Tconst = const T *;

        Tconst consptr();
        
    private:
        T * ptr;
    };
}