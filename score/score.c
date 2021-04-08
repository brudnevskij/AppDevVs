#include "score.h"



int main(void) {
	int scores[MAX], marks[MAX];
	int statistics[6] = {0};

	input_scores(scores);
	evaluation(scores, marks);
	classification(marks, statistics);
	output_results(marks, statistics);
}