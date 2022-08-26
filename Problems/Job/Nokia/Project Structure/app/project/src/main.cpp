#include <async/http/Client.hpp>
#include <async/storage/Storage.hpp>
#include <async/Config.hpp>
#include <json/json.hpp>

int main() {
    async::http::Client client;
    async::storage::Storage storage;
    async::Config config;
    json::Parser parser;
    json::Printer printer;
}