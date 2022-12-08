//
// Created by yxd on 2022/12/8.
//

#ifndef SQLMAKERCPP_LOADFLAG_H
#define SQLMAKERCPP_LOADFLAG_H


class LoadFlag {
public:
    int GetState() { return state; }

    void SetState(int val) { state = val; }

private:
    int state;
};


#endif //SQLMAKERCPP_LOADFLAG_H
