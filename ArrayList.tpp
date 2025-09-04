template <typename T>
ArrayList<T>::ArrayList(int i) {
    if (i <= 0) {
        throw string("Constructor: size must be positive");
    }
    this->maxSize = i;
    this->length = 0;
    this->buffer = new T[maxSize];
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rightObj) {
    if (this != &rightObj) {
        delete[] this->buffer;   // free old memory
        copy(rightObj);          // deep copy
    }
    return *this;
}

template <typename T>
ArrayList<T>::~ArrayList() {
    delete[] this->buffer;
    this->buffer = nullptr;
    this->length = 0;
    this->maxSize = 0;
}

template <typename T>
void ArrayList<T>::copy(const ArrayList<T>& other) {
    this->maxSize = other.maxSize;
    this->length = other.length;
    this->buffer = new T[maxSize];
    for (int i = 0; i < this->length; i++) {
        this->buffer[i] = other.buffer[i];
    }
}

template <typename T>
void ArrayList<T>::append(const T& elem) {
    if (isFull()) {
        throw string("append: error, list is full");
    }
    this->buffer[this->length++] = elem;
}

template <typename T>
void ArrayList<T>::clear() {
    // don't delete buffer, just reset usage
    this->length = 0;
}

template <typename T>
T ArrayList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        throw string("getElement: error, position out of bounds");
    }
    return this->buffer[position];
}

template <typename T>
int ArrayList<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayList<T>::getMaxSize() const {
    return this->maxSize;
}

template <typename T>
void ArrayList<T>::insert(int position, const T& elem) {
    if (isFull()) {
        throw string("insert: error, list is full");
    }
    if (position < 0 || position > this->length) {
        throw string("insert: error, position out of bounds");
    }
    for (int i = this->length; i > position; i--) {
        this->buffer[i] = this->buffer[i - 1];
    }
    this->buffer[position] = elem;
    this->length++;
}

template <typename T>
bool ArrayList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayList<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
void ArrayList<T>::remove(int position) {
    if (position < 0 || position >= this->length) {
        throw string("remove: error, position out of bounds");
    }
    for (int i = position; i < this->length - 1; i++) {
        this->buffer[i] = this->buffer[i + 1];
    }
    this->length--;
}

template <typename T>
void ArrayList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        throw string("replace: error, position out of bounds");
    }
    this->buffer[position] = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const ArrayList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    } else {
        for (int i = 0; i < myObj.length; i++) {
            outStream << myObj.buffer[i] << ' ';
        }
        outStream << endl;
    }
    return outStream;
}
