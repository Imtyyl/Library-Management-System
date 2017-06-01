#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;

class User {
public:
	int id;
	int sf;
	string name;
	string passwd;
}user;

class Book {
public:
	int id;
	string name;
	int num;
	string day;
}book;

int main() {
	cout << "Welcome to BMS" << endl;

	while (1) {
		cout << "Log in as [1] Administrator   [2] User    [0] Quit " << endl;
		int flag;
		cin >> flag;
		while (flag != 1 && flag != 2 && flag != 0) {
			cout << "Please try it again : " << endl;
			cin >> flag;	
		}
        if (flag == 0) break;
		switch (flag) {
			case 1:{
				string username, passwd;

				cout << "Please input your account : " << endl;
				cin >> username;
				cout << "Please input your passwd : " << endl;
				cin >> passdw;

				int success = 0;
				fstream ac("accounts_info.txt");
				while (ac >> user.id >> user.sf >> user.name >> user.passwd) {
					if (user.sf == flag && user.name == username && user.passwd == passwd) {
						success = 1;
						break;
					}
				}

				while (success == 1) {
                    cout << "[1] Search books    [2] Add books    [3] Delete books    [4] List books    [0]Quit" << endl;
                    int flag;
                    cin >> flag;
                    while (flag != 0 && flag != 1 && flag != 2 && flag != 3 && flag != 4) {
                        cout << "Sorry, please try it again" << endl;
                        cin >> flag;
                    }
                    if (flag == 0) break;
                    switch (flag) {
                        case 1:{
                            int success = 0;
                            string bookname;

                            cout << "Please input an bookname : " << endl;
							cin >> bookname;
							fstream bo("books_info.txt");
							while (bo >> book.id >> book.name >> book.num >> book.day) {
								if (book.name == bookname) {
									success = 1;
									break;
								}
							}
							if (success == 1) {
								cout << book.id << ' ' <<book.name << ' ' << book.num << ' ' << book.day << endl;
								while (1) {
									cout << "[1] Modify it    [0] Quit" << endl;
									int flag;
									cin >> flag;
									while (flag != 1 && flag != 0) {
										cout << "Please try it again : " << endl;
										cin >> flag;
									}
									if (flag == 0) break;
                                    switch(flag){
                                        case 1:{
                                            while (1) {
                                                cout << "[1] Change number    [0] Quit" << endl;
                                                int flag;
                                                cin >> flag;
                                                while (flag != 0 && flag != 1) {
                                                    cout << "Sorry, please try it again" << endl;
                                                    cin >> flag;
                                                }
                                                if (flag == 0) break;
                                                switch (flag) {
                                                    case 1:{
                                                        cout << "Please input a number : " << endl;
                                                        int num;
                                                        cin >> num;
                                                        book.num = num;
                                                        fstream bo("books_info.txt", ios::in|ios::out|ios::binary);
                                                        bo.seekp(book.id * sizeof(book), ios::beg);
                                                        bo.write((char *)&book, sizeof(book));
                                                        break;
                                                    }
                                                }
                                            }
                                            break;
                                        }
                                    }
								}
							}
							break;
						}
						case 2:{
							cout << "Please input the infomation of an book : " << endl;
							cin >> book.id >> book.name >> book.num >> book.day;
							fstream bo("books_info.txt");
							bo.seekp(0, ios::end);
							bo << book.id << ' ' << book.name << ' ' << book.num << ' ' << book.day;
                            break;
						}
                        case 4:{
                            while (1) {
                                cout << "[1] All books    [2] Day    [3] Number >=    [4] Number <=    [0] Quit" << endl;
                                int flag;
                                cin >> flag;
                                while (flag != 0 && flag != 1 && flag != 2 && flag != 3 && flag != 4) {
                                    cout << "Sorry, please try it again" << endl;
                                    cin >> flag;
                                }
                                if (flag == 0) break;
                                switch (flag) {
                                    case 1:{
                                        fstream bo("books_info.txt");
                                        while (bo >> book.id >> book.name >> book.num >> book.day) {
                                            cout << book.id << ' ' << book.name << ' ' << book.num << ' ' << book.day << endl;
                                        }
                                        break;
                                    }
                                    case 2:{
                                        string day;
                                        cout << "Please input a day (like 20170530) : " << endl;
                                        cin >> day;
                                        fstream bo("books_info.txt");
                                        while (bo >> book.id >> book.name >> book.num >> book.day) {
                                            if (day == book.day) cout << book.id << ' ' << book.name << ' ' << book.num << ' ' << book.day << endl;
                                        }
                                        break;
                                    }
                                    case 3:{
                                        int num;
                                        cout << "Please input a number : " << endl;
                                        cin >> num;
                                        fstream bo("books_info.txt");
                                        while (bo >> book.id >> book.name >> book.num >> book.day) {
                                            if (book.num >= num) cout << book.id << ' ' << book.name << ' ' << book.num << ' ' << book.day << endl;
                                        }
                                        break;
                                    }
                                    case 4:{
                                        int num;
                                        cout << "Please input a number : " << endl;
                                        cin >> num;
                                        fstream bo("books_info.txt");
                                        while (bo >> book.id >> book.name >> book.num >> book.day) {
                                            if (book.num <= num) cout << book.id << ' ' << book.name << ' ' << book.num << ' ' << book.day << endl;
                                        }
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                    }
                }
                break;
            }

			case 2:{
				string username, passwd;

				cout << "Please input your account : " << endl;
				cin >> username;
				cout << "Please input your passwd : " << endl;
				cin >> passwd;

				int success = 0;
				fstream ac("accounts_info.txt");
				while (ac >> user.id >> user.sf >> user.name >> user.passwd) {
					if (user.sf == flag && user.name == username && user.passwd == passwd) {
						success = 1;
						break;
					}
				}

				if (success == 1) {
					while (1) {
						cout << "[1] Search book    [0] Quit" << endl;
						int flag;
						cin >> flag;
						while (flag != 1 && flag != 0) {
							cout << "Please try it again : " << endl;
							cin >> flag;
						}
                        if (flag == 0) break;
						switch (flag) {
							case 1:{
								int success = 0;
								string bookname;

								cout << "Please input an bookname : " << endl;
								cin >> bookname;
								fstream bo("books_info.txt");
								while (bo >> book.id >> book.name >> book.num >> book.day) {
									if (book.name == bookname) {
										success = 1;
										break;
									}
								}
								if (success == 1) {
									cout << book.name << ' ' << book.num << endl;
									while (1) {
										cout << "[1] Borrow it    [0] Quit" << endl;
										int flag;
										cin >> flag;
										while (flag != 1 && flag != 0) {
											cout << "Please try it again : " << endl;
											cin >> flag;
										}
										if (flag == 0) break;
										switch (flag) {
											case 1:{
												if (book.num == 0) {
													cout << "Sorry" << endl;
													break;
												}
												--book.num;
												bo.seekp(-10, ios::cur);
												bo >> book.num;
												// need to completed
												break;
											}
										}
									}
								}
								break;
							}
						}
					}
				}
				break;
			}
		}
	}
}
