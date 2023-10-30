// Maybe not optimal speed, but who cares, it almost always gets the job done.
std::vector<std::string> split(std::string s, char delimiter) {
  std::vector<std::string> r = { };
  while (s.find(delimiter) != std::string::npos) {
    r.push_back(s.substr(0, s.find(delimiter))); 
    s = s.substr(s.find(delimiter) + 1);
  }
  if (s.size() > 0)
    r.push_back(s);
  return r;
}
