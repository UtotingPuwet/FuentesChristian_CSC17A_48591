#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

struct MveData {
    string title;
    string direc;
    int year,
        mins;
};

struct Movies {
    MveData *movie;
    int nMovies;
};

Movies *getData();
void print (Movies *);
void destroy (Movies *);

int main(){
    Movies *movies;
    
    movies = getData();
    
    print(movies);

    destroy(movies);
    
	//your code here
	return 0;
}

void destroy(Movies *movies) {
    delete []movies->movie;
    delete movies;  
}


Movies *getData() {
    Movies *movies = new Movies;    //new array that will get returned for movies *movies in main.
    
    cout << "This program reviews structures\nInput how many movies, the Title of the Movie, Director, Year Released, and the Running Time in (minutes).\n";
    
    cin>>movies->nMovies;
    
    movies-> movie = new MveData[movies->nMovies];
    
    for (int i = 0; i < movies->nMovies; i++) {
        cin.ignore();
        getline(cin,movies->movie[i].title);
        getline(cin,movies->movie[i].direc);
        cin>>movies->movie[i].year;
        cin>>movies->movie[i].mins;
    }
    return movies;
}

void print (Movies *movies) {
    for (int i = 0; i < movies->nMovies; i++) {
        cout << left<< '\n';
        cout << setw(11) << "Title:" << movies->movie[i].title << '\n';
        cout << setw(11) << "Director:" << movies->movie[i].direc << '\n';
        cout << setw(11) << "Year:" << movies->movie[i].year << '\n';
        cout << setw(11) << "Length:" << movies->movie[i].mins << '\n';
    }
}
