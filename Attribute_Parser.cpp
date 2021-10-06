Q. This challenge works with a custom-designed markup language HRML. In HRML, each element consists of a starting and ending tag, and 
    there are attributes associated with each tag. Only starting tags can have attributes. We can call an attribute by referencing the tag, 
    followed by a tilde, '~' and the name of the attribute. The tags may also be nested.

The opening tags follow the format:

<tag-name attribute1-name = "value1" attribute2-name = "value2" ...>

The closing tags follow the format:

</tag-name>

The attributes are referenced as:

tag1~value  
tag1.tag2~name

Given the source code in HRML format consisting of N lines, answer Q queries. For each query, 
* print the value of the attribute specified. 
* Print "Not Found!" if the attribute does not exist.

// Sample Input

// 4 3
// <tag1 value = "HelloWorld">
// <tag2 name = "Name1">
// </tag2>
// </tag1>
// tag1.tag2~name
// tag1~name
// tag1~value

// Sample Output

// Name1
// Not Found!
// HelloWorld    
    
#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    int n, q;
        string curr = "", attr_name;
        map<string, string> m;
        cin >> n >> q;
        cin.ignore();

        // For every word in the HRML Line (space delimiter), check:
        for (int i = 0; i < n; i++) {
            string line, tag, extract;
            getline(cin, line);
            stringstream ss(line);

            // Process the HRML lines
            while(getline(ss, extract, ' ')) {
                // If it's a tag
                if (extract[0] == '<') {
                    // If it's an opening tag
                    if (extract[1] != '/') {
                        // Remove the opening bracket
                        tag = extract.substr(1);
                        // For tags without attributes
                        if (tag[tag.length() - 1] == '>') {
                            // Remove the closing bracket
                            tag.pop_back();
                        }
                        // Check if any nesting is needed
                        if (curr.size() > 0) {
                            // Nest this tag
                            curr += "." + tag;
                        }
                        else {
                            curr = tag;
                        }
                    }
                    // If it's a closing tag
                    else {
                        tag = extract.substr(2, (extract.find('>') - 2));
                        // Check if a nested tag has to be closed
                        size_t pos = curr.find("." + tag);
                        if (pos != string::npos) {
                            // Remove the nested tag
                            curr = curr.substr(0, pos);
                        }
                        else {
                            // All tags are closed
                            curr = "";
                        }
                    }
                }

                // If's an attribute's value
                else if (extract[0] == '"') {
                    // Capture the full value
                    size_t pos = extract.find_last_of('"');
                    string attr_value = extract.substr(1, pos-1);
                    // Add to the map
                    m[attr_name] = attr_value;
                }

                else {
                    if (extract != "=") {
                        // It's definitely an attribute name
                        attr_name = curr + "~" + extract;
                    }
                }
            }
        }

        // Get the values with the queries
        string query;
        for (int i = 0; i < q; i++) {
            getline(cin, query);

            // Search in the map
            map<string, string>::iterator itr = m.find(query);
            if (itr != m.end()) {
                cout << itr->second << endl;
            }
            else {
                cout << "Not Found!" << endl;
            }
        }
    return 0;
}

/*
 stdin:
 4 3
 <tag1 value = "HelloWorld">
 <tag2 name = "Name1">
 </tag2>
 </tag1>
 tag1.tag2~name
 tag1~name
 tag1~value
 
 output:
 Name1
 Not Found!
 HelloWorldc
 */
