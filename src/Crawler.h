#ifndef CRAWLER_H
#define CRAWLER_H

#include "CurlHTTPClient.h"

#include <regex>

class Crawler {
public:
    Crawler()
        : http_client_(new CurlHTTPClient()) { }

    ~Crawler() {
        delete http_client_;
    }

    std::vector<std::string>
    getOutboundLinks(const std::string &url) {
        std::string body = http_client_->getPage(url);
        std::regex href_regex("href=\"(.*)\"");
        std::smatch href_match;
        std::regex_search(body, href_match, href_regex);
        std::vector<std::string> res;
        for (size_t i = 1; i < href_match.size(); ++i) {
            res.push_back(match);
        }
        return res;
    }

private:
    HTTPClient *http_client_;
};

#endif
