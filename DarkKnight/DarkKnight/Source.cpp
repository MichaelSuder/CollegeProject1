#include <iostream>
#define Log(x) { std::cout << x; }

int main() {
	int ratings[] = { 0, 0, 0 };
	int ratingsLength = sizeof(ratings) / sizeof(ratings[0]);
	const char* question[] = { "Batman Begins - Rating: ", "Dark Knight - Rating: ", "Dark Knight Rises - Rating: " };
	int questionSize = sizeof(question) / sizeof(question[0]);
	const char* movie[] = { "Batman Begins", "Dark Knight", "Dark Knight Rises" };
	bool isRated = false;

	Log("Enter your rating for the folling movies: \n");

	while (!isRated) {
		int rating = 0;
		int validRatings = 0;
		for (int i = 0; i < questionSize; i++)
		{
			Log(question[i]);
			std::cin >> rating;
			ratings[i] = rating;
			while (rating < 1 || rating > 5) {
				Log("Rating must be between 1 and 5. Re-enter: ")
					std::cin >> rating;
				ratings[i] = rating;
			}
		}
		isRated = true;
	}

	int lowest = (ratings[0] < ratings[1] && ratings[0] < ratings[2]) ? ratings[0] : (ratings[1] < ratings[2] ? ratings[2] : ratings[2]);
	int highest = (ratings[0] > ratings[1] && ratings[0] > ratings[2]) ? ratings[0] : (ratings[1] > ratings[2] ? ratings[2] : ratings[2]);
	int avg = (ratings[0] + ratings[1] + ratings[2]) / ratingsLength;

	std::cout << "\nThe ratings you entered were : " << std::endl;
	for (int i = 0; i < ratingsLength; i++)
	{
		std::cout << movie[i] << " " << ratings[i] << std::endl;
	}

	std::cout << "\n\n" << std::endl;

	std::cout << "The Highest Rating was: " << highest << std::endl;
	std::cout << "The lowest rating was: " << lowest << std::endl;
	std::cout << "The average rating was: " << avg << std::endl;

}