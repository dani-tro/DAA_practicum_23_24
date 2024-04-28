 std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<long long> chisla;
    long long n, k;
    std::cin >> n >> k;
    for (size_t i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;
        chisla.push_back(a);
    }

    std::sort(chisla.begin(), chisla.end());

    int firstBr = 1;
    for (size_t i = 1; i < n; i++)
    {
        if (abs(chisla[0] - chisla[i]) <= k)
        {
            firstBr++;
        }
        else
        {
            break;
        }
    }

    int secondBr = 1;
    for (size_t i = n-2; i>=0; i--)
    {
        if (abs(chisla[n-1] - chisla[i]) <= k)
        {
            secondBr++;
        }
        else
        {
            break;
        }
    }

    if (firstBr >= secondBr)
    {
        std::cout << firstBr;
    }
    else
    {
        std::cout << secondBr;
    }