# pip install torch transformers
import torch
from transformers import AutoTokenizer, AutoModelForSequenceClassification


class SentimentService:
    """
    一个简单的情感分类服务类
    功能：输入一句英文，输出 positive 或 negative
    """

    def __init__(self):
        model_name = "sentence-transformers/paraphrase-multilingual-MiniLM-L12-v2

        # 加载分词器
        self.tokenizer = AutoTokenizer.from_pretrained(model_name)

        # 加载分类模型
        self.model = AutoModelForSequenceClassification.from_pretrained(model_name)

        # 设置标签映射
        self.label_map = {
            0: "negative",
            1: "positive"
        }

        # 切换为推理模式
        self.model.eval()

    def predict(self, text: str):
        """
        输入一句文本，返回情感分类结果
        """
        # 处理空输入
        if not text or not text.strip():
            return {"error": "empty input"}

        # 分词并转成模型可接收的张量
        inputs = self.tokenizer(
            text,
            return_tensors="pt",
            truncation=True,
            max_length=128
        )

        # 推理时不计算梯度，节省内存
        with torch.no_grad():
            outputs = self.model(**inputs)

        # 把 logits 转成概率
        probs = torch.softmax(outputs.logits, dim=1)

        # 取概率最大的类别
        pred_id = torch.argmax(probs, dim=1).item()

        # 读取对应标签和置信度
        label = self.label_map[pred_id]
        confidence = probs[0][pred_id].item()

        return {
            "text": text,
            "label": label,
            "confidence": round(confidence, 4)
        }


if __name__ == "__main__":
    service = SentimentService()

    texts = [
        "I like this class.",
        "This movie is terrible.",
        "The food is amazing."
    ]

    for text in texts:
        result = service.predict(text)
        print(result)