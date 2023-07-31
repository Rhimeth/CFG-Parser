import requests
from bs4 import BeautifulSoup

def search_google(query):
    base_url = "https://www.google.com/search"
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.164 Safari/537.36"
    }
    params = {
        "q": query
    }

    response = requests.get(base_url, headers=headers, params=params)
    response.raise_for_status()

    soup = BeautifulSoup(response.text, "html.parser")

    results = []
    for result in soup.find_all("div", class_="tF2Cxc"):
        title = result.find("h3").text
        url = result.find("a")["href"]
        snippet_element = result.find("span", class_="aCOpRe")
        snippet = snippet_element.text if snippet_element else "No snippet available."

        results.append({"title": title, "url": url, "snippet": snippet})

    return results

if __name__ == "__main__":
    search_query = input("Enter your search query: ")
    search_results = search_google(search_query)

    for i, result in enumerate(search_results, start=1):
        print(f"{i}. {result['title']}")
        print(f"   {result['url']}")
        print(f"   {result['snippet']}\n")
