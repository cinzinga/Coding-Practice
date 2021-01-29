import sys
import requests
import json
from bs4 import BeautifulSoup

# Usage, first start the Tor service
# > brew services start tor
# Next run this program and supply the target URL
# > python3 scrape.py <url>

proxies = {
    'http': 'socks5h://127.0.0.1:9050',
    'https': 'socks5h://127.0.0.1:9050'
}

URL = sys.argv[1]
page = requests.get(URL, proxies=proxies)

soup = BeautifulSoup(page.content, 'html.parser')

results = soup.findAll('p')

for r in results:
	print(r.string)