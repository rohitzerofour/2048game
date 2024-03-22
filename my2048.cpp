#include<bits/stdc++.h>
using namespace std;

int board[4][4];
vector<int> available;

int random_generator(){
  int random_ind = rand() % (int)available.size();
  return available[random_ind];
}

int generate_random_power(){
  return ((rand() % 2) + 1);
}

void update_available(){
  available.clear();
  for(int i = 0; i<16; i++){
    int x = i / 4;
    int y = i % 4;
    if(board[x][y] == 0) available.push_back(i);
  }
}

void random_fill(){
  int random_no = random_generator();
  int x = random_no / 4;
  int y = random_no % 4;
  board[x][y] = pow(2, generate_random_power());
  update_available();
}

void init(){
  for(int i = 0; i<4; i++){
    for(int j = 0; j<4; j++){
      board[i][j] = 0;
    }
  }
  update_available();
  for(int i = 0; i<2; i++){
    random_fill();
  }
}

void print(){
  for(int i = 0; i<4; i++){
    for(int j = 0; j<4; j++){
      if(board[i][j] == 0) cout << "  .  ";
      else{
        int cnt = 0;
        int x = board[i][j];
        while(x > 0){
          cnt++;
          x /= 10;
        }
        int spaces = 5-cnt;
        for(int i = 0; i<spaces/2; i++){
          cout << " ";
          cnt++;
        }
        spaces = 5-cnt;
        cout << board[i][j];
        for(int i = 0; i<spaces; i++) cout << " ";
      }
    }
    cout << endl;
  }
}

int make_merges(int *arr){
  vector<int> ans;
  int cnt = 0;
  vector<int> cpy;
  for(int i = 0; i<4; i++) cpy.push_back(arr[i]);
  vector<int> nz;
  for(int i = 0; i<4; i++){
    if(arr[i] != 0) nz.push_back(arr[i]);
  }
  for(int i = 0; i<(int)nz.size(); i++){
    arr[i] = nz[i];
  }
  for(int i = (int)nz.size(); i<4; i++){
    arr[i] = 0;
  }
  for(int i = 0; i<3; i++){
    if(arr[i] == arr[i+1]){
      ans.push_back(arr[i]*2);
      if(i == 1) ans.push_back(arr[3]);
      i++;
    }else if(arr[i] != 0){
      ans.push_back(arr[i]);
      if(i == 2) ans.push_back(arr[3]);
    }
  }
  for(int i = (int)ans.size(); i<4; i++){
    ans.push_back(0);
  }
  for(int i = 0; i<4; i++){
    arr[i] = ans[i];
  }
  for(int i = 0; i<4; i++){
    if(cpy[i] != arr[i]){
      cnt++;
      break;
    }
  }
  return cnt;
}

bool check_win(){
  for(int i = 0; i<4; i++){
    for(int j = 0; j<4; j++){
      if(board[i][j] == 2048){
        return true;
      }
    }
  }
  return false;
}

int main(){
  srand(time(0));
  init();
  while(1){
    print();
    cout << "Enter a move: U, D, L, R or X to exit" << endl;
    char move;
    cin >> move;
    if(move == 'X'){
      cout << "Game ended." << endl;
      break;
    }else if(move == 'U'){
      int cnt = 0;
      for(int i = 0; i<4; i++){
        int arr[4];
        for(int j = 0; j<4; j++){
          arr[j] = board[j][i];
        }
        cnt += make_merges(arr);
        for(int j = 0; j<4; j++){
          board[j][i] = arr[j];
        }
      }
      if(check_win()){
        print();
        cout << "You WIN!" << endl;
        break;
      }else{
        update_available();
        if((int)available.size() > 0){
          if(cnt == 0){
            cout << "No changes. Choose different move." << endl;
          }else{
            random_fill();
          }
        }else{
          print();
          cout << "Game Over." << endl;
          break;
        }
      }
    }else if(move == 'D'){
      int cnt = 0;
      for(int i = 0; i<4; i++){
        int arr[4];
        for(int j = 3; j>=0; j--){
          arr[3-j] = board[j][i];
        }
        cnt += make_merges(arr);
        for(int j = 3; j>=0; j--){
          board[j][i] = arr[3-j];
        }
      }
      if(check_win()){
        print();
        cout << "You WIN!" << endl;
        break;
      }else{
        update_available();
        if((int)available.size() > 0){
          if(cnt == 0){
            cout << "No changes. Choose different move." << endl;
          }else{
            random_fill();
          }
        }else{
          print();
          cout << "Game Over." << endl;
          break;
        }
      }
    }else if(move == 'L'){
      int cnt = 0;
      for(int i = 0; i<4; i++){
        int arr[4];
        for(int j = 0; j<4; j++){
          arr[j] = board[i][j];
        }
        cnt += make_merges(arr);
        for(int j = 0; j<4; j++){
          board[i][j] = arr[j];
        }
      }
      if(check_win()){
        print();
        cout << "You WIN!" << endl;
        break;
      }else{
        update_available();
        if((int)available.size() > 0){
          if(cnt == 0){
            cout << "No changes. Choose different move." << endl;
          }else{
            random_fill();
          }
        }else{
          print();
          cout << "Game Over." << endl;
          break;
        }
      }
    }else if(move == 'R'){
      int cnt = 0;
      for(int i = 0; i<4; i++){
        int arr[4];
        for(int j = 0; j<4; j++){
          arr[j] = board[i][3-j];
        }
        cnt += make_merges(arr);
        for(int j = 0; j<4; j++){
          board[i][3-j] = arr[j];
        }
      }
      if(check_win()){
        print();
        cout << "You WIN!" << endl;
        break;
      }else{
        update_available();
        if((int)available.size() > 0){
          if(cnt == 0){
            cout << "No changes. Choose different move." << endl;
          }else{
            random_fill();
          }
        }else{
          print();
          cout << "Game Over." << endl;
          break;
        }
      }
    }else{
      cout << "Invalid Move." << endl;
    }
  }
}