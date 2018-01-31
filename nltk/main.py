
import nltk

nltk.download('punkt')
nltk.download('averaged_perceptron_tagger')
 
text = nltk.word_tokenize("They refuse to permit us to obtain the refuse permit")
print(text)

tags = nltk.pos_tag(text)
print(tags)
