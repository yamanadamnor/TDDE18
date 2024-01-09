// 1. Open the file passed as an argument to the program.
//    You may assume that there will always be an argument passed
//    to the program (so you don't have to check for it).

// 2. If the file did not exists, print an appropriate message
//    and exit the program.

// 3. Create an appropriate container for tags

// 4. Go through the file, line-by-line and check for tags

// 5. Make sure that the found tag is a valid tag. A valid tag is
//    either a tag or a closing tag that contains only letters.
//    Examples of valid tags: <abc>, </ABC>
//    Examples of invalid tags: <123>, <a tag>
//    If it is invalid, print the message "Invalid tag <tag>", where
//    <tag> is replaced with the found tag, and then exit the program.

// 6. If the found tag is a normal tag, add it to the container.
//    If the found tag is a closing tag, check that it
//    matches the last added tag in the container. If not, then print
//    the error message "Tag <tag> not closed", where <tag> is
//    replaced by the last added tag in the container, and exit the
//    program.

// 7. Once the entire file has been validated, if the container is
//    empty then print the message "Valid XML file!".
//    If the container is not empty then print the message "There are
//    unclosed tags" and exit the program.
