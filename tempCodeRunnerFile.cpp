vector<int> tmp(v.size());
        tmp[0] = v[0];
        for(int i=1; i<v.size(); i++) tmp[i] = tmp[i-1] ^ v[i];