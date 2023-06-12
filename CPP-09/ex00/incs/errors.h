//
// Created by aurel on 6/12/23.
//
#pragma once

/* utils */

# define DATE_PATTERN "^\\d{2}-\\d{2}-\\d{4}\\s$"
# define DATA_FILE_ERRORS	8
# define INPUT_ERRORS		9

/* Error code */

# define BAD_FORMAT 						10
# define WRONG_DATE 						11
# define BAD_INPUT							12
# define NOT_POSITIVE_NUMBER				13
# define WRONG_VALUE						14
#define	 TOO_LARGE_VALUE					15


/* Errors reply */

# define ERR_INPUT( content )				("Error: bad input => " + content + "\n")
# define ERR_DATE( content )				("Error: Wrong date => " + content + "\n")
# define ERR_NOT_POSITIV					"Error: not a positiv number."
# define ERR_WRONG_VALUE					"Error: Value must be a float or a positive integer between 0 and 1000\n"
# define ERR_TOO_LARGE(content)				("Error: too large number => " + content + "\n")