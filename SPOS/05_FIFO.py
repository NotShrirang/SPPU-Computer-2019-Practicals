class Page():
    def __init__(self, page_no: int) -> None:
        self.page_no = page_no


class FIFO():
    def __init__(self, pages: list[Page]) -> None:
        self.total_pages = len(pages)
        self.pages_order = [page.page_no for page in pages]

    def fifo(self):
        pass


class Queue():
    def __init__(self, size: int) -> None:
        self.size = size
        self.queue_array: list[Page] = []
    
    def insert(self, page: Page):
        self.queue_array.append(page)
        return len(self.queue_array)

    def remove(self):
        return self.queue_array.pop(0)

    

if __name__ == '__main__':
    page1 = Page(page_no = 1)
    page2 = Page(page_no = 3)
    page3 = Page(page_no = 4)
    page4 = Page(page_no = 2)
    pages = [page1, page2, page3, page4]

    fifo = FIFO(pages = pages)