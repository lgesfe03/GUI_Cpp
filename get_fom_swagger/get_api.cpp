#include <curl/curl.h>
#include <iostream>
#include <string>

class ApiRequest {
public:
    ApiRequest(const std::string& baseUrl) : baseUrl(baseUrl) {
        curl_global_init(CURL_GLOBAL_ALL);
    }

    ~ApiRequest() {
        curl_global_cleanup();
    }

    std::string getChargePointInfo() {
        CURL* curl = curl_easy_init();
        std::string response;

        if (curl) {
            std::string url = baseUrl + "/api/getchargepointinfo";
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &ApiRequest::writeCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

            CURLcode res = curl_easy_perform(curl);
            if (res != CURLE_OK) {
                std::cerr << "Failed to perform HTTP request: " << curl_easy_strerror(res) << std::endl;
            }

            curl_easy_cleanup(curl);
        } else {
            std::cerr << "Failed to initialize curl." << std::endl;
        }

        return response;
    }

private:
    std::string baseUrl;

    static size_t writeCallback(char* ptr, size_t size, size_t nmemb, std::string* data) {
        data->append(ptr, size * nmemb);
        return size * nmemb;
    }
};

int main() {
    ApiRequest apiRequest("http://192.168.56.1:9999");

    std::string chargePointInfo = apiRequest.getChargePointInfo();
    std::cout << "Charge Point Info: " << chargePointInfo << std::endl;

    return 0;
}