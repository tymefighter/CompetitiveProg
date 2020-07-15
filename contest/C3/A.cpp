class RadarFinder {
    private:
        inline long long sq(long long x) {return x * x;}
    public:

        int possibleLocations(
            int x1, 
            int y1, 
            int r1, 
            int x2, 
            int y2, 
            int r2
        ) {

            if(x1 == x2 && y1 == y2)
                return (r1 == r2 ? -1 : 0);

            long long centerDistSq =
                sq(static_cast<long long>(x1) - x2)
                +
                sq(static_cast<long long>(y1) - y2);

            long long radiusSumSq = 
                sq(static_cast<long long>(r1) + r2);

            if(centerDistSq > radiusSumSq)
                return 0;
            else if(centerDistSq == radiusSumSq)
                return 1;
            else {
                long long radiusDifSq =
                    sq(static_cast<long long>(r1) - r2);

                if(centerDistSq > radiusDifSq)
                    return 2;
                else if(centerDistSq == radiusDifSq)
                    return 1;
                else
                    return 0;
            }
        }
};