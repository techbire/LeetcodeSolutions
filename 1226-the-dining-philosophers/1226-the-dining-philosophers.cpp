class DiningPhilosophers {
public:

    vector<mutex> v = vector<mutex>(5);
    DiningPhilosophers() {

    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		
        int leftFork = philosopher;
        int rightFork = (philosopher+4)%5;

        unique_lock<mutex> lck1(v[leftFork],defer_lock);
        unique_lock<mutex> lck2(v[rightFork],defer_lock);

        if(philosopher==4){
            lck2.lock();
            lck1.lock();
            pickLeftFork();
            pickRightFork();
        }

        else{
            lck1.lock();
            lck2.lock();
            pickLeftFork();
            pickRightFork();
        }

        eat();
        putLeftFork();
        putRightFork();
        lck1.unlock();
        lck2.unlock();
    }
};