def main():
    s=input()
    if(len(s)!=8):
        print("Well-Being")
        return
    ss=['a','e','i','o','u']
    st = set(ss)
    for i in range(1,8,2):
        if s[i] not in st:
            print("Well-Being")
            return
    for i in range(0,8,2):
        if s[i] in st:
            print("Well-Being")
            return
    print("Suspected Virus")
for i in range(int(input())):
    main()