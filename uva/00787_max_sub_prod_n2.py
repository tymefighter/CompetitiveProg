from sys import stdin

def main():

    prods, prods_temp = [], []
    max_val = None


    for line in stdin:
        line = line.split()

        for val in line:
            val = int(val)

            if val == -999999:
                prods, prods_temp = [], []
                print(max_val)
                break
            
            if len(prods) == 0:

                prods.append(val)
                max_val = val
                continue
            
            prods_temp.append(val)
            max_val = max(val, max_val)
            for i, x in enumerate(prods):
                prods_temp.append(x * val)
                max_val = max(prods_temp[i+1], max_val)
            
            prods = prods_temp[:]
            prods_temp = []


if __name__ == '__main__':

    main()